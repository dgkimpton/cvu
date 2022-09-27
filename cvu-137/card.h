#pragma once
#include <string>
#include <compare>

namespace PlayingCards {
  enum class Suit { hearts = 1, diamonds, spades, clubs };
  struct Rank {
    explicit Rank(int);
    inline explicit operator int() const noexcept { return value; }
    auto operator<=> (Rank const &) const = default;
   private:
    int value;
  };
  struct Card {
    Rank rank;
    Suit suit;
    auto operator<=> (Card const &) const = default;
  };
  Card parse(std::string const &);
  Suit parse_suit(std::string const &);
}