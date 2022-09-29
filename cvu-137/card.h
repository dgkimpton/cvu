#pragma once
#include <string>
#include <compare>
#include <stdexcept>

namespace PlayingCards {
  enum class Suit { hearts = 1, diamonds, spades, clubs };

  class Rank {
    int value;
   public:
    explicit Rank(int);
    inline explicit operator int() const noexcept { return value; }
    auto operator<=> (Rank const &) const = default;
  };

  struct Card {
    Rank rank;
    Suit suit;
    auto operator<=> (Card const &) const = default;
  };

  Card parse(std::string const &);
  Suit parse_suit(std::string const &);
  Rank parse_rank(std::string const &);

  class ParseError : public std::runtime_error {
   public:
    explicit ParseError(std::string const &str, std::string const &msg);
  };
}