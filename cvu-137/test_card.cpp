#include "catch.hpp"
#include "card.h"
#include "card_helpers.h"
using namespace PlayingCards;

TEST_CASE("it should be possible to parse english language descriptions of playing cards") {
  CHECK(parse("ace of hearts") == Card{Rank{1}, Suit::hearts});
}

TEST_CASE("it should be possible to parse a suit from a string") {
  CHECK(parse_suit("hearts") == Suit::hearts);
  CHECK(parse_suit("diamonds") == Suit::diamonds);
  CHECK(parse_suit("spades") == Suit::spades);
  CHECK(parse_suit("clubs") == Suit::clubs);

  CHECK_THROWS_AS(parse_suit(""), std::invalid_argument);
  CHECK_THROWS_WITH(parse_suit(""), Catch::Contains("not a suit"));

  CHECK_THROWS_AS(parse_suit("fish"), std::invalid_argument);
  CHECK_THROWS_WITH(parse_suit("fish"), Catch::Contains("fish"));
}

TEST_CASE("the numeric values of suits should be sequential from one") {
  CHECK(static_cast<int>(Suit::hearts) == 1);
  CHECK(static_cast<int>(Suit::diamonds) == 2);
  CHECK(static_cast<int>(Suit::spades) == 3);
  CHECK(static_cast<int>(Suit::clubs) == 4);
}

TEST_CASE("ranks should always be in the range [1, 13]") {
  CHECK(static_cast<int>(Rank{1}) == 1);
  CHECK(static_cast<int>(Rank{5}) == 5);
  CHECK(static_cast<int>(Rank{13}) == 13);

  CHECK_THROWS_AS(Rank{0}, std::out_of_range);
  CHECK_THROWS_AS(Rank{14}, std::out_of_range);
  CHECK_THROWS_AS(Rank{-1}, std::out_of_range);
  CHECK_THROWS_WITH(Rank{-1}, Catch::Contains("rank range"));
}

TEST_CASE("it should be possible to parse a rank from a string") {
  CHECK(parse_rank("ace") == Rank{1});
  CHECK(parse_rank("2") == Rank{2});
  CHECK(parse_rank("10") == Rank{10});
  CHECK(parse_rank("jack") == Rank{11});
  CHECK(parse_rank("queen") == Rank{12});
  CHECK(parse_rank("king") == Rank{13});

  CHECK_THROWS_AS(parse_rank(""), std::invalid_argument);
  CHECK_THROWS_WITH(parse_rank(""), Catch::Contains("invalid rank"));

  CHECK_THROWS_AS(parse_rank("other"), std::invalid_argument);
  CHECK_THROWS_WITH(parse_rank("other"), Catch::Contains("invalid rank"));
  CHECK_THROWS_WITH(parse_rank("other"), Catch::Contains("other"));

  CHECK_THROWS_AS(parse_rank("0"), std::invalid_argument);
  CHECK_THROWS_AS(parse_rank("-1"), std::invalid_argument);
  CHECK_THROWS_AS(parse_rank("14"), std::invalid_argument);
}

TEST_CASE("it should not be possible to parse face cards by value") {
  CHECK_THROWS_AS(parse_rank("1"), std::invalid_argument);
  CHECK_THROWS_AS(parse_rank("11"), std::invalid_argument);
  CHECK_THROWS_AS(parse_rank("12"), std::invalid_argument);
  CHECK_THROWS_AS(parse_rank("13"), std::invalid_argument);
}