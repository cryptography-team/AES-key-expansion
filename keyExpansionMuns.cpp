#include "keyExpansion.h"
using AES::keyExpansion;

word keyExpansion::subWord(const word &w) const {
  word resword = 0;
  // To retrieve the transform word, call the subByte function four times.
  for (int i = 0; i < 4; i++) {
    resword <<= 8;
    resword |= subByte(w >> ((3 - i) * 8));
  }
  return resword;
}

void keyExpansion::expand(byte key[16], word w[44]) const {
  initExpand(key, w);
  word tmp;
  for (int i = 4; i < 44; i++) {
    tmp = w[i - 1];
    if (i % 4 == 0)
      tmp = subWord(rotWord(tmp)) ^ (word(RC[i / 4 - 1]) << 24);
    w[i] = w[i - 4] ^ tmp;
  }
}
