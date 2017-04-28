//
// Created by Sigbjørn Lund Olsen on 28/04/2017.
//

#ifndef SPIRIT_FRUIT_COMMON_H
#define SPIRIT_FRUIT_COMMON_H

namespace x3 = boost::spirit::x3;

enum class FRUIT {
	APPLES,
	ORANGES
};

std::string to_string(FRUIT fruit);

namespace parser {
	using iterator_type = std::string::const_iterator;
	using context_type = x3::phrase_parse_context<x3::ascii::space_type>::type;
}

#endif //SPIRIT_FRUIT_COMMON_H
