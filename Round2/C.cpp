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

#define INF 1e18

using namespace std;

vector <int64_t> RT;

int64_t update(int idx, int i, int l, int r, int64_t val) {
  if (i < l || i > r) return INF;
  if (l == r && l == i) return RT[idx] = val;
  int mid = (l + r) / 2;
  update(2 * idx, i, l, mid, val);
  update(2 * idx + 1, i, mid + 1, r, val);
  return RT[idx] = min(RT[2 * idx], RT[2 * idx + 1]);
}

int64_t query(int idx, int i, int j, int l, int r) {
  if (l >= i && r <= j) return RT[idx];
  if (j < l || i > r) return 1e18;
  int mid = (l + r) / 2;
  int64_t left = query(2 * idx, i, j, l, mid);
  int64_t right = query(2 * idx + 1, i, j, mid + 1, r);
  return min(left, right);
}

void solve() {
  int N, l, r;
  cin >> N;
  vector <int64_t> W(N);
  for (int i = 0; i < N - 1; i++) cin >> W[i];

  RT = vector<int64_t>(4 * N, INF);
  update(1, 0, 0, N - 1, W[0]);

  for (int i = 1; i < N; i++) {
    cin >> l >> r;
    int64_t left = query(1, l - 1, r - 1, 0, N - 1);
    left += W[i];
    update(1, i, 0, N - 1, left);
  }

  for (int i = 1; i < N; i++) cout << query(1, i, i, 0, N - 1) - W[i] << ' ';
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) solve();
}
