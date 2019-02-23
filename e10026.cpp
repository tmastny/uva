#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> job_sequence(vector<tuple<int, int, int>> &tasks) {

  vector<int> v = {1, 2, 3};
  return v;
}

void print_sequence(vector<int> &seq) {
  for (auto el : seq) {
    cout << el << " ";
  }
  cout << endl;
}

int main() {

  int cases;
  cin >> cases;

  for (int i = 0; i < cases; i++) {
    string empty_line;
    getline(cin, empty_line);


    vector<tuple<int, int, int>> tasks;
    int tasks_number;
    cin >> tasks_number;
    for (int j = 0; j < tasks_number; j++) {
      int time;
      int fine;
      cin >> time;
      cin >> fine;

      tasks.push_back(make_tuple(j + 1, time, fine));
    }

    vector<int> seq = job_sequence(tasks);
    print_sequence(seq);
  }
}
