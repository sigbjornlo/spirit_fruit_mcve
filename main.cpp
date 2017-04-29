
#include <iostream>

#include <boost/spirit/home/x3.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include "common.h"
#include "fruit.h"

namespace ast {
	struct FruitType {
		std::string identifier;
		FRUIT fruit;
	};
}

BOOST_FUSION_ADAPT_STRUCT(ast::FruitType, identifier, fruit);

namespace parser {
	// Identifier
	using identifier_type = x3::rule<class identifier, std::string>;
	const auto identifier = identifier_type {"Identifier"};
	const auto identifier_def = x3::raw[x3::lexeme[(x3::alpha | '_') >> *(x3::alnum | '_')]];
	BOOST_SPIRIT_DEFINE(identifier);

	// FruitType
	struct fruit_type_class;
	const auto fruit_type = x3::rule<fruit_type_class, ast::FruitType> {"FruitType"};

	// Using the sequence operator creates a grammar which fails gracefully given invalid input.
	// const auto fruit_type_def = identifier >> ':' >> make_fruit_grammar();

	// Using the expectation operator causes EXC_BAD_ACCESS exception with invalid input.
	// Instead, I would have expected an expectation failure exception.
	// Indeed, an expectation failure exception is thrown when the fruit grammar is defined here in this compilation unit instead of in fruit.cpp.
	const auto fruit_type_def = identifier > ':' > make_fruit_grammar();

	BOOST_SPIRIT_DEFINE(fruit_type);
}

int main() {
	std::string input = "GrannySmith: Mammals";
	parser::iterator_type it = input.begin(), end = input.end();

	const auto& grammar = parser::fruit_type;
	auto result = ast::FruitType {};

	try {
		bool successful_parse = boost::spirit::x3::phrase_parse(it, end, grammar, boost::spirit::x3::ascii::space, result);
		if (successful_parse && it == end) {
			std::cout << "Parsing succeeded!\n";
			std::cout << result.identifier << " is a kind of " << to_string(result.fruit) << "!\n";
		} else {
			std::cout << "Parsing failed!\n";
		}
	} catch(...) {
		std::cout << "Exception raised\n";
	}

	return 0;
}

std::string to_string(FRUIT fruit) {
	switch (fruit) {
		case FRUIT::APPLES: return "apple";
		case FRUIT::ORANGES: return "orange";
	}
	return "nothing";
}
