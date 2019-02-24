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

int task_time(vector<tuple<int, int, int>> &tasks) {
  int sum = 0;
  for (auto el : tasks) {
    sum += get<TIME>(el);
  }

  return sum;
}

vector<int> job_order(vector<tuple<int, int, int>> &tasks, vector<int> &order) {
  //vector<int> order;
  order.clear();
  int days_left = task_time(tasks);

  while (tasks.size() > 0) {

    int max_delay_cost = 0;
    vector<tuple<int, int, int>>::iterator max_it;
    for (auto it = tasks.begin(); it != tasks.end(); it++) {

      int delay_cost = (days_left - get<TIME>(*it)) * get<FINE>(*it);

      if (delay_cost > max_delay_cost) {
        max_delay_cost = delay_cost;
        max_it = it;
      }
    }

    order.push_back(get<INDEX>(*max_it));
    days_left -= get<TIME>(*max_it);

    tasks.erase(max_it);
  }

  return order;
}

void print_job_order(vector<int> &seq) {
  for (int i = 0; i < seq.size(); i++) {
    cout << seq[i];
    if (i < seq.size() - 1) {
      cout << " ";
    }
  }

  cout << endl;
}

int main() {

  int cases;
  cin >> cases;

  vector<tuple<int, int, int>> tasks;
  vector<int> jobs;
  for (int i = 0; i < cases; i++) {
    string empty_line;
    getline(cin, empty_line);

    tasks.clear();
    jobs.clear();

    int tasks_number;
    cin >> tasks_number;
    for (int j = 0; j < tasks_number; j++) {
      int time;
      int fine;
      cin >> time >> fine;

      tasks.push_back(make_tuple(j + 1, time, fine));
    }

    //vector<int> jobs = job_order(tasks, jobs);
    job_order(tasks, jobs);
    print_job_order(jobs);
  }
}
