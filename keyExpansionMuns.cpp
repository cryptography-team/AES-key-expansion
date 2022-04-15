#include "keyExpansion.h"
using AES::keyExpansion;
// Forward substitute byte transformation function
// Multiply each row of the transformation matrix by the byte to be converted.
// To get the result bit, perform an XOR operation on each result byte from the
// multiplication on all bits. Now that we have a multiply result byte, we can
// XOR it with the xorColumn to get the final result.
byte keyExpansion ::transformByte(const byte &b) const {
  byte res = 0;
  byte sub;
  for (int i = 0; i < 8; i++) {
    sub = transformationMatrix[i] * b;
    // __builtin_popcount() function returns the number of ones
    res |= (__builtin_popcount(sub) & 1) << i;
  }
  return res ^ xorColumn;
}

byte keyExpansion ::subByte(const byte &b) const {
  return keyExpansion::transformByte(b);
}

word keyExpansion ::subWord(const word &w) const {
  word resword = 0;
  // To retrieve the transform word, call the subByte function four times.
  for (int i = 0; i < 4; i++) {
    resword <<= 8;
    resword |= subByte(w >> i * 8);
  }
  return resword;
}

void keyExpansion ::expand(byte key[16], word w[44]) const {
  init(key, w);
  word tmp;
  for (int i = 4; i < 44; i++) {
    tmp = w[i - 1];
    if (i % 4 == 0)
      tmp = subWord(rotWord(tmp)) ^ RC[i / 4] << 24;
    w[i] = w[i - 4] ^ tmp;
  }
}
