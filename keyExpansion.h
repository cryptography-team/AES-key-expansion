#ifndef KEY_EXPANSION_HEADER
#define KEY_EXPANSION_HEADER

namespace AES {

class keyExpansion {
protected:
  typedef unsigned char byte;
  typedef unsigned int word;

  const byte RC[10], transformationMatrix[8], xorColumn;

public:
  keyExpansion();
  void init(byte key[16], word w[4]) const;
  byte transformByte(const byte &b) const;
  byte subByte(const byte &b) const;
  word subWord(const word &w) const;
  word rotWord(const word &w) const;
  void expand(byte key[16], word w[44]) const;
};

} // namespace AES

#endif
