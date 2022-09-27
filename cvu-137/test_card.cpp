#include "catch.hpp"
#include "card.h"
#include "card_helpers.h"
using namespace PlayingCards;

TEST_CASE("it should be possible to parse english language descriptions of playing cards") {
  CHECK(parse("ace of hearts") == Card{1, Suit::hearts});
}

TEST_CASE("it should be possible to parse a suit from a string") {
  CHECK(parse_suit("hearts") == Suit::hearts);
  CHECK(parse_suit("diamonds") == Suit::diamonds);
}