#include <bits/stdc++.h>

int N;
std::vector<int> V, S;
std::vector<std::vector<int>> pos;
std::queue<int> Q;
int count;

std::vector<int> RMQ;

void init(int p, int L, int R) {
  if (L == R){
    RMQ[p] = L;
  }
  else {
    init(2*(p), L, (L + R) / 2);
    init(2*(p)+1, (L + R) / 2 + 1, R);
    int p1 = RMQ[2*(p)], p2 = RMQ[2*(p)+1];
    RMQ[p] = (S[p1] <= S[p2]) ? p1 : p2;
  }
}

int rmq(int p, int L, int R, int i, int j) {  
  if (i > R || j < L) return -1;       
  if (L >= i && R <= j) return RMQ[p];  
  int p1 = rmq(2*(p), L, (L + R) / 2, i, j);
  int p2 = rmq(2*(p)+1, (L + R) / 2 + 1, R, i, j);
  if (p1 == -1) return p2;  
  if (p2 == -1) return p1;  
  return (S[p1] <= S[p2]) ? p1 : p2;
} 

void dp(int i, int j)
{
  if(i > j) return;
  int m = rmq(1, 0, N-1, i, j);
  V[m] = count--;
  dp(m+1, j);
  dp(i, m-1);
}

int main()
{
  std::cin >> N;
  V.resize(N);
  S.resize(N+1);
  pos.resize(N+1);
  RMQ.resize(4*N, 0);

  for(int i=0; i<N; i++) std::cin >> S[i];

  init(1, 0, N-1);

  count = N;
  dp(0, N-1);

  for(int i=0; i<N; i++) std::cout << V[i] << " ";
  std::cout << std::endl;

  return 0;
}
