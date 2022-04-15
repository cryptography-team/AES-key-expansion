#include "keyExpansion.h"
#include <iomanip>
#include <iostream>
using namespace AES;
using namespace std;
int main() {
  keyExpansion tool;
  word input;
  word expandKEy[44];
  byte key[16];
  cout << "Enter your key \n";
  for (word i = 0; i < 16; i++) {
    // To get hex inputs, use the built-in stl function hex.
    cin >> hex >> input;
    key[i] = input;
  }
  tool.expand(key, expandKEy);
  cout << "\nThe expanded key is: \n";
  for (unsigned int i = 0, round = 1, cont = 4; i < 44; ++cont, i++) {
    if (cont == 4) {
      cout << dec << endl
           << "Round " << setfill(' ') << setw(2) << round << ": ";
      round++;
      cont = 0;
    }
    // fill empty places with '0'
    cout << setfill('0') << setw(8);
    cout << hex << expandKEy[i] << " ";
  }
  return 0;
}
