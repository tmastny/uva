#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <iterator>
#include <algorithm>
#include <utility>
#include <cmath>

#define INDEX 0
#define TIME 1
#define FINE 2

using namespace std;

bool compare(tuple<int, int ,int> &a, tuple<int, int ,int> &b) {
  return get<INDEX>(a) < get<INDEX>(b);
}

int task_time(vector<tuple<int, int, int>> &tasks) {
  int sum = 0;
  for (auto el : tasks) {
    sum += get<TIME>(el);
  }

  return sum;
}

void job_order(vector<tuple<int, int, int>> &tasks) {
  int days_left = task_time(tasks);

  for (int i = 0; i < tasks.size(); i++) {

    int max_delay_cost = 0;
    auto max_it = tasks.begin() + i;
    for (auto it = max_it; it != tasks.end(); it++) {

      int delay_cost = (days_left - get<TIME>(*it)) * get<FINE>(*it);

      if (delay_cost > max_delay_cost) {
        max_delay_cost = delay_cost;
        max_it = it;
      }
    }

    swap(*max_it, tasks[i]);
    days_left -= get<TIME>(*max_it);
  }
}

void print_job_order(vector<tuple<int, int, int>> &seq) {
  for (int i = 0; i < seq.size(); i++) {
    cout << get<INDEX>(seq[i]);
    if (i < seq.size() - 1) {
      cout << " ";
    }
  }

  cout << endl;
}

int job_cost(vector<tuple<int, int, int>> &tasks) {
  int cost = 0;
  int delay = 0;
  for (auto el : tasks) {
    cost += delay * get<FINE>(el);
    delay += get<TIME>(el);
  }

  return cost;
}

int min_job_cost(vector<tuple<int, int, int>> &tasks) {
  sort(tasks.begin(), tasks.end(), compare);

  int min_cost = job_cost(tasks);
  for (int i = 0; i < tgamma(tasks.size() + 1); i++) {
    int cost = job_cost(tasks);
    if (cost < min_cost) {
      min_cost = cost;
      print_job_order(tasks);
    }
    next_permutation(tasks.begin(), tasks.end(), compare);
  }

  return min_cost;
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
    cout << endl;
    cout << "Task: " << i << " " << tasks_number << endl;

    int best_min = min_job_cost(tasks);
    cout << "Min cost: " << best_min << endl;

    job_order(tasks);

    cout << "Found cost: " << job_cost(tasks) << endl;

    print_job_order(tasks);
  }
}
