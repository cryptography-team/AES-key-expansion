#include "keyExpansion.h"
using AES::keyExpansion;

byte keyExpansion :: transformByte(const byte &b) const
{
    byte res = 0;
    byte sub;
    for (int i = 0; i < 8; i++)
    {
        sub = transformationMatrix[i] * b;
        res |= (__builtin_popcount(sub) & 1) << i;
    }
    return res^xorColumn;

} // muns
byte keyExpansion :: subByte(const byte &b) const
{
    return transformbyte(b);
}          // muns
word keyExpansion :: subWord(const word &w) const
{
    word resword = 0;
    for(int i =0 ; i<4; i++)
    {
        resword |= subByte(w>>i*8);
    }
    return resword;
}           // muns
void keyExpansion :: expand(byte key[16], word w[44]) const
{
    word tmp;
    for (int i=4; i < 44; i++)
    {
        tmp = w[i-1];
        if (i % 4 == 0)
            tmp = SubWord(rotWord(tmp)) ^ RC[i/4]<<24;
        w[i] = w[i-4] ^ tmp;
    }
}
