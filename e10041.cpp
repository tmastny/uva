#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {

  int cases;
  cin >> cases;

  for (int i = 0; i < cases; i++) {
    string line;
    while (getline(cin, line)) {

    }
  }

  string a;
  string b;
  while(getline(cin, a)) {
    getline(cin, b);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    deque<char> qa;
    qa.assign(a.begin(), a.end());

    deque<char> qb;
    qb.assign(b.begin(), b.end());

    cout << matching_letters(qa, qb) << endl;
  }
}
