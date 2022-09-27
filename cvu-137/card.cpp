#include "card.h"
#include <stdexcept>
namespace PlayingCards {
  Card parse(std::string const &) {
    return Card{1, Suit::hearts};
  }

  Suit parse_suit(const std::string &str) {
    if (str == "hearts") return Suit::hearts;
    if (str == "diamonds") return Suit::diamonds;
    throw std::invalid_argument("not a suit: " + str);
  }
}