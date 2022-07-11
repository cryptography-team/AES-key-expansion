#include "keyExpansion.h"
#include <iomanip>
#include <iostream>
using namespace AES;
using namespace std;
int main() {
  keyExpansion tool;
  word expandKey[44];
  AES::byte key[16];
  cout << "Enter your key:" << endl;
  // Hold the values in a proper form in a stringstream
  stringstream ss;
  for (int i = 0; i < 32; i++) {
    char c;
    cin >> c;
    if (i % 2 == 0)
      ss << ' ';
    ss << c;
  }
  for (int i = 0; i < 16; i++) {
    word input;
    // To get hex inputs, use the built-in stl function hex.
    ss >> hex >> input;
    key[i] = input;
  }
  tool.expand(key, expandKey);
  cout << "\nThe expanded key is: \n";
  for (int i = 0, round = 1, cont = 4; i < 44; ++cont, i++) {
    if (cont == 4) {
      cout << dec << endl
           << "Round " << setfill(' ') << setw(2) << round << ": ";
      round++;
      cont = 0;
    }
    // fill empty places with '0'
    cout << setfill('0') << setw(8);
    cout << hex << expandKey[i] << " ";
  }
  return 0;
}
