#include "card.h"
#include <stdexcept>
namespace PlayingCards {
  Rank::Rank(int val) : value{val} {
    if (val < 1 || val > 13) {
      throw std::out_of_range("rank range is [1, 13], got: " + std::to_string(val));
    }
  }

  Card parse(std::string const &) {
    return Card{Rank{1}, Suit::hearts};
  }

  Suit parse_suit(const std::string &str) {
    if (str == "hearts") return Suit::hearts;
    if (str == "diamonds") return Suit::diamonds;
    if (str == "spades") return Suit::spades;
    if (str == "clubs") return Suit::clubs;
    throw std::invalid_argument("not a suit: " + str);
  }

  Rank parse_rank(const std::string &str) {
    if (str == "ace") return Rank{1};
    if (str == "jack") return Rank{11};
    if (str == "queen") return Rank{12};
    if (str == "king") return Rank{13};

    try {
      auto value = std::stoi(str);
      if (value > 1 && value < 11) {
        return Rank{value};
      }
      throw std::out_of_range("face cards must be specified by name");
    } catch (const std::logic_error &ex) {
      throw std::invalid_argument("invalid rank <" + str + "> " + ex.what());
    }
  }
}