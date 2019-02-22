#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <cmath>
#include <map>

using namespace std;

void decode(vector<string> &dict, vector<string> &words) {
  map<char, int> dict_freq = letter_freq(dict);
  map<char, int> encoded_freq = letter_freq(words);

  for(auto &word : words) {
    for(int i = 0; i < word.size(); i++) {
      encoded_freq.count(word[i]);
    }
  }
}

map<char, int> letter_freq(vector<string> &words) {
  map<char, int> freq;
  for(auto &word : words) {
    for(int i = 0; i < word.size(); i++) {
      freq[word[i]]++;
    }
  }

  return freq;
}

int main() {
  vector<string> dict;

  int words;
  cin >> words;

  string word;
  for(int i = 0; i < words; i++) {
    cin >> word;
    dict.push_back(word);
  }

  string line;
  while(getline(cin, line)) {

    vector<string> encrypted_words;

    string encrypted;
    std::istringstream iss(line);
    while(iss >> encrypted) {
      encrypted_words.push_back(encrypted);
    }



    encrypted_words.clear();
  }
}
