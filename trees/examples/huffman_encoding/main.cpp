#include <iostream>
#include <string>
#include <unordered_map>
#include "huffman_tree.h"

using namespace std;

string encode(string to_encode,
   const unordered_map<char, string>& encoding_map)
{
   string result = "";
   for (int i = 0; i < to_encode.length(); i++)
   {
      char ch = to_encode[i];
      string encoded = encoding_map.at(ch);
      result = result + encoded;
   }
   return result;
}

int main()
{
   unordered_map<char, int> frequency_map;
   frequency_map[' '] = 7;
   frequency_map['a'] = 4;
   frequency_map['e'] = 4;
   frequency_map['f'] = 3;
   frequency_map['h'] = 2;
   frequency_map['i'] = 2;
   frequency_map['m'] = 2;
   frequency_map['n'] = 2;
   frequency_map['s'] = 2;
   frequency_map['t'] = 2;
   frequency_map['l'] = 1;
   frequency_map['o'] = 1;
   frequency_map['p'] = 1;
   frequency_map['r'] = 1;
   frequency_map['u'] = 1;
   frequency_map['x'] = 1;
   HuffmanTree tree(frequency_map);

   unordered_map<char, string> encoding_map = tree.encoding_map();
   string encoded = encode("this is an example of a huffman tree", encoding_map);
   cout << encoded << endl;
   string decoded = tree.decode(encoded);
   cout << decoded << endl;
   return 0;
}
