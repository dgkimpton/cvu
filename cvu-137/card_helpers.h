#pragma once
#include <string>
#include <sstream>
#include "card.h"
// Functions used exclusively by the Catch2 testing framework
namespace PlayingCards {
  std::string stream_extract_string(Card const &);
  std::ostream & operator<< (std::ostream &, Card const &);
  std::string stream_extract_string(Suit const &);
  std::ostream & operator<< (std::ostream &os, Suit const &);
}


