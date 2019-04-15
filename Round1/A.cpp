#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);

string rtrim(const string &);

/*
 * Complete the 'exam' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY v as parameter.
 */

int exam(vector<int> v) {

  int a = 0, b = 0;
  for (int x : v) b += x ? +1 : -1;

  int k = 0;
  while (k < v.size() && a <= b) {
    a += v[k] ? +1 : -1;
    b -= v[k] ? +1 : -1;
    k++;
  }

  return k;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string v_count_temp;
  getline(cin, v_count_temp);

  int v_count = stoi(ltrim(rtrim(v_count_temp)));

  vector<int> v(v_count);

  for (int i = 0; i < v_count; i++) {
    string v_item_temp;
    getline(cin, v_item_temp);

    int v_item = stoi(ltrim(rtrim(v_item_temp)));

    v[i] = v_item;
  }

  int result = exam(v);

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

