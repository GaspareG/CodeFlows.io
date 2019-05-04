#include <bits/stdc++.h>

int N, L;

long long int solve()
{
  std::cin >> N >> L;
  std::vector<std::array<long long int,2>> PC(N);
  for(int i=0; i<N; i++) std::cin >> PC[i][0];
  for(int i=0; i<N; i++) std::cin >> PC[i][1];

  std::sort(PC.begin(), PC.end());
  std::vector<long long int> DP(N+1, 0);
  std::vector<long long int> SOL(N+1, 0);

  SOL[0] = DP[0] = PC[0][1];
  int j=0;
  for(int i=1; i<N; i++)
  {
    DP[i] = PC[i][1];

    DP[i] = std::max(DP[i], SOL[i-1]);

    // prendo
    for(j=std::max(0, j-2); j<N; j++)
    {
      if(PC[i][0] - PC[j][0] <= L) break;
      DP[i] = std::max(DP[i], SOL[j] + PC[i][1]);
    }
 
    SOL[i] = std::max(SOL[i-1], DP[i]);
  }

  return SOL[N-1];
}

int main()
{
  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) std::cout << solve() << std::endl;
  return 0;
}
