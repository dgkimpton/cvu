#include "card.h"
namespace PlayingCards {
  Card parse(std::string const &) {
    return Card{1, Suit::hearts};
  }
}