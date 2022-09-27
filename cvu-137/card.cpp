#include "card.h"
#include <stdexcept>
#include <sstream>
namespace PlayingCards {
  Rank::Rank(int val) : value{val} {
    if (val < 1 || val > 13) {
      throw std::out_of_range("rank range is [1, 13], got: " + std::to_string(val));
    }
  }

  Card parse(std::string const &str) {
    std::istringstream iss{str};
    std::string rank, of, suit;

    if (!(iss >> rank >> of >> suit))
      throw std::invalid_argument("too little input: " + str);

    if (!iss.eof())
      throw std::invalid_argument("too much input: " + str);

    if (of != "of")
      throw std::invalid_argument("expected 'of', found: " + of);

    return Card{parse_rank(rank), parse_suit(suit)};
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