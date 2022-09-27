#include "card.h"
#include <stdexcept>
namespace PlayingCards {
  Rank::Rank(int val) : value{val} {
    if (val < 1 || val > 13) {
      throw std::out_of_range("rank range is [1, 13], got: " + std::to_string(val));
    }
  }

  Card parse(std::string const &) {
    return Card{1, Suit::hearts};
  }

  Suit parse_suit(const std::string &str) {
    if (str == "hearts") return Suit::hearts;
    if (str == "diamonds") return Suit::diamonds;
    if (str == "spades") return Suit::spades;
    if (str == "clubs") return Suit::clubs;
    throw std::invalid_argument("not a suit: " + str);
  }
}