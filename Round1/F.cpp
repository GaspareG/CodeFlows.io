#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);

string rtrim(const string &);

/*
 * Complete the 'getTimes' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY time
 *  2. INTEGER_ARRAY direction
 */

vector<int> getTimes(vector<int> time, vector<int> direction) {
  int n = time.size();
  array<int, 2> last = {-2, 0}; // {time, direction}
  int current = 0;

  vector<int> sol(n, 0);
  queue<int> Q[2]; // Q[0] in, Q[1] out

  for (int i = 0; i < n; i++) Q[direction[i]].push(i);

  Q[0].push(n);
  Q[1].push(n);

  while (Q[0].size() > 1 || Q[1].size() > 1) {

    int topIn = Q[0].front();
    int topOut = Q[1].front();

    if ((topIn == n || time[topIn] > current) && (topOut == n || time[topOut] > current)) {
      if (topIn == n) current = time[topOut];
      else if (topOut == n) current = time[topIn];
      else current = min(time[topIn], time[topOut]);
    }

    int toServe = n;
    if (topIn == n) toServe = topOut;
    else if (topOut == n) toServe = topIn;
    else {
      if (time[topIn] > current) toServe = topOut;
      else if (time[topOut] > current) toServe = topIn;
      else {
        if (current != (last[0] + 1) || last[1] == 1) toServe = topOut;
        else toServe = topIn;
      }
    }

    if (toServe != n && time[toServe] <= current) {
      sol[toServe] = current;
      Q[toServe != topIn].pop();
      last = {current, direction[toServe]};
    }

    current++;
  }

  return sol;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string time_count_temp;
  getline(cin, time_count_temp);

  int time_count = stoi(ltrim(rtrim(time_count_temp)));

  vector<int> time(time_count);

  for (int i = 0; i < time_count; i++) {
    string time_item_temp;
    getline(cin, time_item_temp);

    int time_item = stoi(ltrim(rtrim(time_item_temp)));

    time[i] = time_item;
  }

  string direction_count_temp;
  getline(cin, direction_count_temp);

  int direction_count = stoi(ltrim(rtrim(direction_count_temp)));

  vector<int> direction(direction_count);

  for (int i = 0; i < direction_count; i++) {
    string direction_item_temp;
    getline(cin, direction_item_temp);

    int direction_item = stoi(ltrim(rtrim(direction_item_temp)));

    direction[i] = direction_item;
  }

  vector<int> result = getTimes(time, direction);

  for (int i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(
      s.begin(),
      find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
  );

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end()
  );

  return s;
}

