#include <bits/stdc++.h>

using namespace std;

int nextInt() {
  int out = 0, c = 0;
  while (c < '0' || c > '9') c = getchar_unlocked();
  while (c >= '0' && c <= '9') {
    out = (out << 3) + (out << 1) + (c - '0');
    c = getchar_unlocked();
  }
  return out;
}

int main() {
  int N, Q;
  N = nextInt();
  Q = nextInt();

  vector<int> V(N + 1);
  for (int i = 1; i <= N; i++) V[i] = nextInt();

  vector <array<int, 4>> H(Q);
  vector<int> sol(Q, 0);

  for (int i = 0; i < Q; i++) {
    cin >> H[i][2]; // X
    cin >> H[i][0]; // L
    cin >> H[i][1]; // R
    H[i][3] = i;    // IDX
  }

  vector<int> seen(1e5 + 1, 0);

  for (int i = 0; i < Q; i++) {
    int l = H[i][0];
    int r = H[i][1];
    int x = H[i][2];
    int s = 0;    // size
    int sum = 0;  // sum
    int lidx = l; // left index
    queue<int> q;

    for (int k = l; k <= r; k++) {
      q.push(V[k]);
      if (seen[V[k]] == 0) sum += V[k];
      seen[V[k]]++;

      while (q.size() > 0 && sum > x) {
        int t = q.front();
        q.pop();
        if (seen[t] == 1) sum -= t;
        seen[t]--;
      }

      s = max((int) q.size(), s);
    }

    while (q.size() > 0) {
      seen[q.front()]--;
      q.pop();
    }

    cout << s << endl;
  }

  return 0;
}

