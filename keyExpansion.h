#ifndef KEY_EXPANSION_HEADER
#define KEY_EXPANSION_HEADER
#include <iostream>
using namespace std;
typedef unsigned char byte;
typedef unsigned int word;
namespace AES {

class keyExpansion {
protected:
  byte RC[10], substitutionTable[16][16];

public:
  keyExpansion();
  void initExpand(byte key[16], word w[4]) const;
  void initTable();
  word subWord(const word &w) const;
  word rotWord(const word &w) const;
  void expand(byte key[16], word w[44]) const;
};

} // namespace AES

#endif
