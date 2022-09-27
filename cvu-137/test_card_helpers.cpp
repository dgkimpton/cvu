#include "catch.hpp"
#include "card_helpers.h"
// There requirements are introduced by the testing framework Catch2 and are not part of the program specification
using namespace PlayingCards;

TEST_CASE("it should be possible to convert a Card to a string") {
  CHECK(stream_extract_string(Card{1, Suit::hearts}) == "1 of hearts");
}
TEST_CASE("it should be possible to convert a Suit to a string") {
  CHECK(stream_extract_string(Suit::hearts) == "hearts");
  CHECK(stream_extract_string(Suit::diamonds) == "diamonds");
  CHECK(stream_extract_string(Suit::spades) == "spades");
  CHECK(stream_extract_string(Suit::clubs) == "clubs");
}