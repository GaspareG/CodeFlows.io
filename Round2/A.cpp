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

int solve() {
  int K, M;
  cin >> K >> M;
  vector <std::array<int, 3>> V(K, {0, 0, 0});
  for (int i = 0; i < K; i++) V[i][2] = i + 1;
  for (int i = 0; i < M; i++) {
    int x;
    cin >> x;
    x--;
    V[x][0]++;
    V[x][1] = -i;
  }

  sort(V.begin(), V.end());
  return V[0][2];
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) cout << solve() << std::endl;
  return 0;
}
