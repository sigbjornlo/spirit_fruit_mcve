//
// Created by Sigbjørn Lund Olsen on 28/04/2017.
//

#ifndef SPIRIT_FRUIT_FRUIT_H
#define SPIRIT_FRUIT_FRUIT_H

#include <boost/spirit/home/x3.hpp>

#include "common.h"

namespace parser {
	struct fruit_class;
	using fruit_grammar = x3::rule<fruit_class, FRUIT>;

	BOOST_SPIRIT_DECLARE(fruit_grammar)

	fruit_grammar make_fruit_grammar();
}


#endif //SPIRIT_FRUIT_FRUIT_H
