#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);

string rtrim(const string &);

/*
 * Complete the 'minOperations' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long minOperations(long n) {
  long sol = 0;
  for (; n; n = n >> 1) sol ^= n;
  return sol;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  long n = stol(ltrim(rtrim(n_temp)));

  long result = minOperations(n);

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

