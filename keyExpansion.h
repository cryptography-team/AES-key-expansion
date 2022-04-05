#ifndef KEY_EXPANSION_HEADER
#define KEY_EXPANSION_HEADER

namespace AES {

class keyExpansion {
private:
  typedef unsigned char byte;
  typedef unsigned int word;

  byte RC[10];

public:
  void init(byte key[16], word w[4]);
  word subWord(const word &w) const;
  word rotWord(const word &w) const;
  void expand(byte key[16], word w[44]) const;
};

} // namespace AES

#endif
