#include "keyExpansion.h"

using AES::keyExpansion;

// This function initializes the constants as described in the reference
keyExpansion::keyExpansion() {
  // RC is used to obtain Rcon
  RC[0] = 0x01;
  for (int i = 1; i < 8; ++i)
    RC[i] = RC[i - 1] << 1;
  RC[8] = 0x1B;
  RC[9] = 0x36;

  initTable();
}

// This function puts the given key into the first four words
void keyExpansion::initExpand(byte key[16], word w[4]) const {
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j) {
      // Left byte shift
      w[i] <<= 8;
      w[i] |= key[4 * i + j];
    }
}

// This function makes a left cyclic byte shift by discarding the last byte and
// ORing it at the beginning (32 - 8 = 24)
word keyExpansion::rotWord(const word &w) const { return (w << 8) | (w >> 24); }
