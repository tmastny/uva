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

bool job_compare(const tuple<int, int ,int> &a, const tuple<int, int ,int> &b) {
  return get<TIME>(a) * get<FINE>(b) < get<TIME>(b) * get<FINE>(a);
}

int task_time(vector<tuple<int, int, int>> &tasks) {
  int sum = 0;
  for (auto el : tasks) {
    sum += get<TIME>(el);
  }

  return sum;
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

void print_job_tuple(vector<tuple<int, int, int>> &seq) {
  for (auto el : seq) {
    cout << "(" << get<INDEX>(el) << ", " << get<TIME>(el)
      << ", " << get<FINE>(el) << ")" << endl;
  }
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

bool index_compare(tuple<int, int ,int> &a, tuple<int, int ,int> &b) {
  return get<INDEX>(a) < get<INDEX>(b);
}

int min_job_cost(vector<tuple<int, int, int>> &tasks, bool print = true) {
  int min_cost = job_cost(tasks);
  for (int i = 0; i < tgamma(tasks.size() + 1); i++) {
    int cost = job_cost(tasks);
    if (cost < min_cost) {
      min_cost = cost;
      if (print) {
        print_job_order(tasks);
      }
    }
    next_permutation(tasks.begin(), tasks.end(), index_compare);
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
    //cout << endl;
    //cout << "Task: " << i << " " << tasks_number << endl;

    //int best_min = min_job_cost(tasks, false);
    //cout << "Min cost: " << best_min << endl;

    stable_sort(tasks.begin(), tasks.end(), job_compare);
    //cout << "Found cost: " << job_cost(tasks) << endl;

    //print_job_tuple(tasks);
    print_job_order(tasks);

    if (i < cases - 1) {
      cout << endl;
    }
  }
}
