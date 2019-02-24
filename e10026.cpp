#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <iterator>
#include <algorithm>

#define INDEX 0
#define TIME 1
#define FINE 2

using namespace std;

bool compare2(const tuple<int, int> &a, const tuple<int, int> &b) {
  return get<1>(a) < get<1>(b);
}

vector<int> job_order(vector<tuple<int, int, int>> &tasks) {
  int days_remaining = tasks.size();
  vector<int> job_order;

  int max_job_cost = 0;
  vector<tuple<int, int, int>>::iterator max_it;
  for (auto it = tasks.begin(); it != tasks.end(); it++) {
    int job_cost = (days_remaining - get<TIME>(*it)) * get<FINE>(*it);
    if (job_cost > max_job_cost) {
      max_job_cost = job_cost;
      max_it = it;
    }
  }

  // the problem is deleting the element each time is linear
  tasks.erase(max_it);
  job_order.push_back(get<INDEX>(*max_it));
}

void print_job_order(vector<int> &seq) {
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
      cin >> time >> fine;

      tasks.push_back(make_tuple(j + 1, time, fine));
    }

    vector<int> jobs = job_order(tasks);
    print_job_order(jobs);
  }
}
