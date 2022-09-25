#pragma once
#include <string>
#include <compare>

namespace PlayingCards {
  enum class Suit { hearts };
  struct Card {
    int rank;
    Suit suit;
    auto operator<=> (Card const &) const = default;
  };
  Card parse(std::string const &);
}