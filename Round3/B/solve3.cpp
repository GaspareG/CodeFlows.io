#include <bits/stdc++.h>


long long int solve()
{
  int N, L;
  std::cin >> N >> L;
  std::vector<std::array<int,2>> PC(N);
  for(int i=0; i<N; i++) std::cin >> PC[i][0];
  for(int i=0; i<N; i++) std::cin >> PC[i][1];

  std::sort(PC.begin(), PC.end());
  std::vector<std::vector<long long int>> DP(2, std::vector<long long int>(N+2, 0));

  std::vector<long long int> S0(N+2, 0);
  std::vector<long long int> S1(N+2, 0);

  long long int mm=0;
  // 0 non prendo
  // 1 prendo
  for(int i=N-1; i>=0; i--)
  {
    DP[0][i] = mm;//std::max(DP[0][i+1], DP[1][i+1]);
    DP[1][i] = PC[i][1];

    for(int j=N-1; j>i; j--)
    {
      if(PC[j][0] - PC[i][0] > L)
      {
        DP[1][i] = std::max(DP[1][i], PC[i][1]+S1[j]);
      }
    }

    S0[i] = std::max(S0[i+1], DP[0][i]);
    S1[i] = std::max(S1[i+1], DP[1][i]);
    mm = std::max(mm, std::max(DP[0][i], DP[1][i]));
  }

  return mm; // std::max(DP[0][0], DP[1][0]);
}

int main()
{
  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) std::cout << solve() << std::endl;
  return 0;
}
