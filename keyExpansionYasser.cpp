#include "keyExpansion.h"

using AES::keyExpansion;

keyExpansion::keyExpansion() : xorColumn(0x63) {
  RC[0] = 0x01;
  for (int i = 1; i < 8; ++i)
    RC[i] = RC[i - 1] << 1;
  RC[8] = 0x1B;
  RC[9] = 0x36;

  transformationMatrix[0] = 0xF1;
  for (int i = 1; i < 8; ++i)
    transformationMatrix[i] =
        (transformationMatrix[i - 1] << 1) | (transformationMatrix[i - 1] >> 7);
}

void keyExpansion::init(byte key[16], word w[4]) const {
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++i) {
      w[i] <<= 8;
      w[i] |= key[4 * i + j];
    }
}

word rotWord(const word &w) const { return (word << 8) | (word >> 24); }
