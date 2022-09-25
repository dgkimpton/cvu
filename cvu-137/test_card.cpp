#include "catch.hpp"
#include "card.h"
using namespace PlayingCards;

TEST_CASE("it should be possible to parse english language descriptions of playing cards") {
  CHECK(parse("ace of hearts") == Card{1, Suit::hearts});
}