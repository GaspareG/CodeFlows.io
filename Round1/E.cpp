#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);

string rtrim(const string &);

/*
 * Complete the 'findBreakDuration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER t
 *  4. INTEGER_ARRAY start
 *  5. INTEGER_ARRAY finish
 */

int findBreakDuration(int n, int k, int t, vector<int> start, vector<int> finish) {
  vector<int> f;
  int sol = 0, att = 0;
  k++;

  f.push_back(start[0]);
  for (int i = 0; i < n - 1; i++) f.push_back(start[i + 1] - finish[i]);
  f.push_back(t - finish[n - 1]);

  for (int i = 0; i < k; i++) att += f[i];
  sol = att;
  for (int i = k; i < f.size(); i++) sol = max(sol, att = att - f[i - k] + f[i]);

  return sol;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string k_temp;
  getline(cin, k_temp);

  int k = stoi(ltrim(rtrim(k_temp)));

  string t_temp;
  getline(cin, t_temp);

  int t = stoi(ltrim(rtrim(t_temp)));

  string start_count_temp;
  getline(cin, start_count_temp);

  int start_count = stoi(ltrim(rtrim(start_count_temp)));

  vector<int> start(start_count);

  for (int i = 0; i < start_count; i++) {
    string start_item_temp;
    getline(cin, start_item_temp);

    int start_item = stoi(ltrim(rtrim(start_item_temp)));

    start[i] = start_item;
  }

  string finish_count_temp;
  getline(cin, finish_count_temp);

  int finish_count = stoi(ltrim(rtrim(finish_count_temp)));

  vector<int> finish(finish_count);

  for (int i = 0; i < finish_count; i++) {
    string finish_item_temp;
    getline(cin, finish_item_temp);

    int finish_item = stoi(ltrim(rtrim(finish_item_temp)));

    finish[i] = finish_item;
  }

  int result = findBreakDuration(n, k, t, start, finish);

  fout << result << "\n";

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
