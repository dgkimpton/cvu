#include "card_helpers.h"
#include <sstream>
namespace PlayingCards {
  std::string stream_extract_string(Card const &value) {
    std::ostringstream oss; oss << value; return oss.str();
  }
  std::ostream & operator<< (std::ostream &os, Card const &card) {
    os << card.rank << " of " << card.suit;
    return os;
  }
  std::string stream_extract_string(Suit const &value) {
    std::ostringstream oss; oss << value; return oss.str();
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
}