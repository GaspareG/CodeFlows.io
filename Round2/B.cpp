#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

string find(int N, int K) {
  if (!(N <= K && K <= 26 * N)) return "";
  string out(N, 'a');
  K -= N;
  for (int i = N - 1; i >= 0; i--) {
    int inc = min(25, K);
    out[i] += inc;
    K -= inc;
  }
  return out;
}

void solve() {
  int N, K;
  cin >> N >> K;
  string A = find(N, K);
  string B = A;
  reverse(B.begin(), B.end());
  if (A.size() != N) cout << "-1" << endl;
  cout << A << " " << B << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) solve();
  return 0;
}
