#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <iterator>
#include <algorithm>

using namespace std;

int minimum_distance_to_relatives(vector<int> &addresses) {
  int n = (addresses.size() - 1) / 2;

  nth_element(addresses.begin(), addresses.begin() + n, addresses.end());

  int median = addresses[n];
  int distance = 0;
  for (int i = 0; i < addresses.size(); i++) {
    distance += abs(addresses[i] - median);
  }

  return distance;
}

int main() {

  int cases;
  cin >> cases;

  for (int i = 0; i < cases; i++) {
    int relatives;
    cin >> relatives;

    vector<int> addresses;
    string line;
    getline(cin, line);
    std::istringstream iss(line);

    int n;
    while(iss >> n) {
      addresses.push_back(n);
    }

    cout << minimum_distance_to_relatives(addresses) << endl;
  }
}
