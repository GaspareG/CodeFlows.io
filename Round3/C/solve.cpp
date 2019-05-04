#include <bits/stdc++.h>

std::vector<std::vector<int>> G;
std::vector<int> memo;

int dfs(int u)
{
  if(memo[u] == -1)
  {
    memo[u] = 1;
    for(auto v : G[u]) memo[u] += dfs(v);
  }
  return memo[u];
}

int solve()
{
  int N;
  std::cin >> N;
  G.clear();
  G.resize(N);
  memo.clear();
  memo.resize(N, -1);

  for(int i=0; i<N-1; i++)
  {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
  }

  int sol=0;
  for(int i=0; i<N; i++) sol = std::max(sol, dfs(i));

  return sol;
}

int main()
{
  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) std::cout << solve() << std::endl;
  return 0;
}
