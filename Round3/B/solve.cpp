#include <bits/stdc++.h>


int solve()
{
  int N, L;
  std::cin >> N >> L;
  std::vector<std::array<int,2>> PC(N);
  for(int i=0; i<N; i++) std::cin >> PC[i][0];
  for(int i=0; i<N; i++) std::cin >> PC[i][1];

  std::sort(PC.begin(), PC.end());
  std::vector<int> mr(N+1, 0);
  for(int i=N-1; i>=0; i--)
    mr[i] = std::max(mr[i+1], PC[i][1]);

  int sol=0;
  for(int i=0; i<N; i++)
  {
    auto pos = std::lower_bound(PC.begin(), PC.end(), std::array<int, 2>{PC[i][0]+L+1, -1}) - PC.begin();
    sol = std::max(sol, PC[i][1]+mr[pos]);
  }

  return sol;
}

int main()
{
  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) std::cout << solve() << std::endl;
  return 0;
}


