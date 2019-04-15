#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);

string rtrim(const string &);


#define MOD 1000000007

/*
 * Complete the 'countMessages' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY keys
 *  2. STRING message
 */

long long combination(int count, int length) {
  if (length == 1ll) return 1ll;
  if (count == 1ll) return 1ll;
  if (count == 2ll) return 2ll;
  if (count == 3ll) return 4ll;

  if (length == 3ll) {
    long long v[] = {1ll, 2ll, 4ll, 0ll};
    for (int i = 4; i <= count; i++) {
      v[3] = (((v[0] + v[1]) % MOD) + v[2]) % MOD;
      v[0] = v[1];
      v[1] = v[2];
      v[2] = v[3];
    }
    return v[3];
  }

  if (count == 4ll) return 8ll;

  long long v[] = {1ll, 2ll, 4ll, 8ll, 0ll};
  for (int i = 5; i <= count; i++) {
    v[4] = (((v[0] + v[1]) % MOD) + ((v[2] + v[3]) % MOD)) % MOD;
    v[0] = v[1];
    v[1] = v[2];
    v[2] = v[3];
    v[3] = v[4];
  }

  return v[4];
}

int countMessages(vector <string> keys, string message) {
  map<char, string> mapping;
  string seq = "";

  for (int i = 0; i < keys.size(); i++) {
    string cs = "";
    for (char c : keys[i]) {
      cs += ('2' + i);
      mapping[c] = cs;
    }
  }
  mapping[' '] = '1';

  for (char c : message) seq += mapping[c];

  long long sol = 1;
  for (int i = 0; i < seq.size(); i++) {
    long long count = 1;
    while (i + count < seq.size() && seq[i] == seq[i + count]) count++;
    long long size = 1;
    if (seq[i] >= '2') size = keys[seq[i] - '2'].size();
    long long solI = combination(count, size);
    sol = ((sol % MOD) * (solI % MOD)) % MOD;

    i += count - 1;
  }
  return (int) (sol % MOD);
}


int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string keys_count_temp;
  getline(cin, keys_count_temp);

  int keys_count = stoi(ltrim(rtrim(keys_count_temp)));

  vector <string> keys(keys_count);

  for (int i = 0; i < keys_count; i++) {
    string keys_item;
    getline(cin, keys_item);

    keys[i] = keys_item;
  }

  string message;
  getline(cin, message);

  int result = countMessages(keys, message);

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

