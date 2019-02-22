#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <iterator>
#include <algorithm>

using namespace std;

string matching_letters(deque<char> a, deque<char> b) {
  string match = "";
  while (a.size() > 0 && b.size() > 0) {
    if (a[0] > b[0]) {
      b.pop_front();
    } else if (b[0] > a[0]) {
      a.pop_front();
    } else {
      match += a[0];
      a.pop_front();
      b.pop_front();
    }
  }

  return match;
}

int main() {

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
