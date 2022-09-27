#include "card_helpers.h"
#include <sstream>
namespace PlayingCards {
  std::ostream & operator<< (std::ostream &os, Card const &card) {
    os << card.rank << " of " << card.suit;
    return os;
  }
  std::ostream & operator<< (std::ostream &os, Suit const &suit) {
    switch (suit) {
      case Suit::hearts: os << "hearts"; break;
      case Suit::diamonds: os << "diamonds"; break;
      case Suit::spades: os << "spades"; break;
      case Suit::clubs: os << "clubs"; break;
    }
    return os;
  }
  std::ostream & operator<< (std::ostream &os, Rank const &rank) {
    os << static_cast<int>(rank);
    return os;
  }
}