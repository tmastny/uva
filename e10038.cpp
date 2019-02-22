#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <cmath>

using namespace std;

string is_jolly_jumper(vector<int> &seq) {
  int elements = seq[0];
  if(elements == 1) {
    return "Jolly";
  }

  set<int> differences;

  int sum = 0;
  for(int i = 2; i < seq.size(); i++) {
    int diff = abs(seq[i] - seq[i - 1]);
    if(differences.count(diff) || diff < 1 || diff > elements - 1) {
      return "Not jolly";
    }
    differences.insert(diff);
  }
  return "Jolly";
}

int main() {
  int n;
  string line;
  vector<int> v;
  while(getline(cin, line)) {

    std::istringstream iss(line);
    while(iss >> n) {
      v.push_back(n);
    }

    cout << is_jolly_jumper(v) << '\n';



    v.clear();
  }
}
