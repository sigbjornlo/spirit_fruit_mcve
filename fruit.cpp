//
// Created by Sigbjørn Lund Olsen on 28/04/2017.
//

#include "fruit.h"

namespace parser {
	struct fruit_symbol_table : x3::symbols<FRUIT> {
		fruit_symbol_table() {
			add
					("Apples", FRUIT::APPLES)
					("Oranges", FRUIT::ORANGES);
		}
	};

	struct fruit_class;
	const auto fruit = x3::rule<fruit_class, FRUIT> {"Fruit"};
	const auto fruit_def = fruit_symbol_table {};
	BOOST_SPIRIT_DEFINE(fruit);

	BOOST_SPIRIT_INSTANTIATE(fruit_grammar, iterator_type, context_type);

	const fruit_grammar& make_fruit_grammar() {
		return fruit;
	}
}