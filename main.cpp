#include <iostream>
#include "keyExpansion.h"
using namespace AES;
using std::cin;
using std::hex;
using std::cout;
using std::endl;
int main()
{
    word x;
    word expandKEy[44];
    byte key[16] ;
    cout<<"Enter your key \n";
    for(word i = 0 ; i<16;i++)
    {
        cin >> hex >> x;
        key[i] = x;
    }
    keyExpansion tool ;
    tool.expand(key,expandKEy);
    cout<<"\n Expansion key is \n";
    for(word i = 0,cont=1;i<44;++cont,i++)
    {
        cout<<expandKEy[i]<<" ";
        if(cont == 4)
        {
            cout<<endl;
            cont = 0;
        }
    }



    return 0;
}
