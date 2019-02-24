#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <iterator>
#include <algorithm>

using namespace std;

struct job {
  int num;
  int time;
  int fine;
}

bool sort_by_third(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
  return get<2>(a) > get<2>(b);
}

bool max_job()

void sort_jobs(vector<tuple<int, int, int>> &tasks) {
  int days_remaining = tasks.size();

  vector<tuple<int, int>> delayed_costs;
  for (auto job : tasks) {
    int job_cost = (days_remaining - get<1>(job)) * get<2>(job);
    delayed_costs.push_back(make_tuple(get<0>(job), job_cost);
  }

  auto next_job = max_element(delayed_costs.begin(), delayed_costs.end());

  sort(tasks.begin(), tasks.end(), sort_by_third);
}

void print_job_order(vector<tuple<int, int, int>> &seq) {
  for (auto el : seq) {
    cout << get<0>(el) << " ";
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

    sort_jobs(tasks);
    print_job_order(tasks);
  }
}
