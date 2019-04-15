#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector <vector<int>> memo;
vector <vector<vector < int>>>
memog;

#define LSOne(i) (i & (-i))

class FenwickTree {
private:
  vector<int> BIT;
  int _N;

public:
  FenwickTree(int N) {
    BIT.assign(N + 1, 0);
    _N = N;
  }

  FenwickTree(int N, int *v) {
    BIT.assign(N + 1, 0);
    _N = N;
    for (int i = 0; i < N; i++)
      update(i + 1, v[i]);
  }

  void update(int i, int inc) {
    while (i <= _N) {
      BIT[i] += inc;
      i += LSOne(i);
    }
  }

  int RSQ(int i) {
    int res = 0;
    while (i > 0) {
      res += BIT[i];
      i -= LSOne(i);
    }
    return res;
  }

  int RSQ(int i, int j) {
    return RSQ(j) - RSQ(i - 1);
  }
};

vector <FenwickTree> memop;

int f(int i, int j) {
  if (i >= j) return 0;
  if (memo[i][j] != -1) return memo[i][j];
  int sol = 1e9;
  for (int k = i + 1; k <= j + 1; k++) {
    int cost = 0;
    cost += f(i + 1, k - 1);
    cost += f(k, j);

    cost += memog[i][i + 1][k - 1];
    cost += (j - k + 1) - (memog[i][i + 1][j] - memog[i][i + 1][k - 1]);
    cost += memog[i + 1][k][j];
    sol = min(sol, cost);
  }
  return memo[i][j] = sol;
}

int main() {
  int N;
  cin >> N;
  v.resize(N);
  memo.resize(N, vector<int>(N, -1));
  memog.resize(N + 1, vector < vector < int >> (N + 1, vector<int>(N + 1, 0)));
  memop.resize(N + 1, FenwickTree(N + 1));
  for (int i = 0; i < N; i++)
    cin >> v[i];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (v[i] > v[j])
        memop[i].update(j + 1, 1);
      else
        memop[i].update(j + 1, 0);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j; k < N; k++) {
        int sol = memop[k].RSQ(i + 1, j + 1 - 1);
        sol += memog[i][j][k - 1];
        memog[i][j][k] = sol;
      }
    }
  }
  cout << f(0, N - 1) << endl;
}
