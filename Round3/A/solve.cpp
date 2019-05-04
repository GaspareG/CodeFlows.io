#include <bits/stdc++.h>

using ll = long long int;

int main()
{
  ll N, M, R, K;
  std::cin >> N >> M >> R >> K;

  std::vector<ll> P(N);
  std::vector<ll> A(M);
  std::set<ll> T;
  std::vector<std::set<ll>> top(N);

  // costo pizza
  for(auto i=0; i<N; i++) std::cin >> P[i];

  // aggiunte
  for(auto i=0; i<M; i++) std::cin >> A[i];

  // topping che voglio
  for(auto i=0; i<K; i++)
  {
    ll tmp;
    std::cin >> tmp;
    tmp--;
    T.insert(tmp);
  }

  for(auto i=0; i<N; i++)
  {
    ll S;
    std::cin >> S;
    for(auto j=0; j<S; j++)
    {
      ll tmp;
      std::cin >> tmp;
      std::cerr << "PIZZA " << i << " -> " << tmp << std::endl;
      tmp--;
      top[i].insert(tmp);
    }
  }

  ll sol = -1;

  for(auto i=0; i<N; i++)
  {
    ll cost = P[i];
    std::cerr << "COSTO " << i << ": " << cost << std::endl;

    for(ll ing : top[i])
    {
      if(T.find(ing) == T.end())
      {
        cost += R;
        std::cerr << "\t" << "TOLGO " << ing+1 << " + " << A[ing] << std::endl;
      }
      else
      {
        std::cerr << "\t" << "NON TOLGO " << ing+1 << " + " << A[ing] << std::endl;
      }
      std::cerr << "COSTO " << i << ": " << cost << std::endl;
    }

    for(ll ing : T)
    {
      if(top[i].find(ing) == top[i].end())
      {
        std::cerr << "\t" << "AGGIUNGO " << ing+1 << " + " << A[ing] << std::endl;
        cost += A[ing];
      }
    }

    std::cerr << "COSTO " << i << ": " << cost << std::endl;
    std::cerr << std::endl;

    if(sol == -1) sol = cost;
    else sol = std::min(cost, sol);
  }

  std::cout << sol << std::endl;
  return 0;
}
