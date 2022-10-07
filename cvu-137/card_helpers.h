#pragma once
#include <string>
#include <sstream>
#include "card.h"
// Functions used exclusively by the Catch2 testing framework
namespace PlayingCards {
  template<typename T>
  std::string stream_extract_string(T const &value) {
    std::ostringstream oss; oss << value; return oss.str();
  }
  std::ostream & operator<< (std::ostream &, Card const &);
  std::ostream & operator<< (std::ostream &os, Suit const &);
  std::ostream & operator << (std::ostream &, Rank const &);
}


