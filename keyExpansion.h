#ifndef KEY_EXPANSION_HEADER
#define KEY_EXPANSION_HEADER
typedef unsigned char byte;
typedef unsigned int word;
namespace AES {

class keyExpansion {
protected:
  byte RC[10], transformationMatrix[8], xorColumn;

public:
  keyExpansion();                              // yasser
  void init(byte key[16], word w[4]) const;    // yasser
  byte transformByte(const byte &b) const;     // muns
  byte subByte(const byte &b) const;           // muns
  word subWord(const word &w) const;           // muns
  word rotWord(const word &w) const;           // yasser
  void expand(byte key[16], word w[44]) const; // muns
};

} // namespace AES

#endif
