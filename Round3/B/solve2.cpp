#include <bits/stdc++.h>

int solve()
{
  int N, L;
  std::cin >> N >> L;
  std::vector<std::array<int,2>> PC(N);
  for(int i=0; i<N; i++) std::cin >> PC[i][0];
  for(int i=0; i<N; i++) std::cin >> PC[i][1];

  std::sort(PC.begin(), PC.end());

  int sol = 0;
  for(int i=0; i<N; i++)
  {
    sol = std::max(sol, PC[i][1]);
    for(int j=i+1; j<N; j++)
    {
      if(PC[j][0] - PC[i][0] > L)
      {
        sol = std::max(sol, PC[i][1]+PC[j][1]);
      }
    }
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
