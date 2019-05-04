#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
 private:
  vector<int> st, A;
  int n;
  int left(int p) { return p << 1; } 
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {  
    if (L == R){
      st[p] = L;                     
    }
    else {                           
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] >= A[p2]) ? p1 : p2;
    }
  }

  int rmq(int p, int L, int R, int i, int j) {  
    if (i > R || j < L) return -1;       
    if (L >= i && R <= j) return st[p];  
    int p1 = rmq(left(p), L, (L + R) / 2, i, j);
    int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
    if (p1 == -1) return p2;  
    if (p2 == -1) return p1;  
    return (A[p1] >= A[p2]) ? p1 : p2;
  } 

  int update_point(int p, int L, int R, int idx, int new_value) {
    int i = idx, j = idx;
    if (i > R || j < L) return st[p];
    if (L == i && R == j) {
      A[i] = new_value;  
      return st[p] = L;  
    }
    int p1, p2;
    p1 = update_point(left(p), L, (L + R) / 2, idx, new_value);
    p2 = update_point(right(p), (L + R) / 2 + 1, R, idx, new_value);
    return st[p] = (A[p1] >= A[p2]) ? p1 : p2;
  }

 public:
  SegmentTree(){}
  SegmentTree(vector<int>& _A) {
    A = _A;
    n = (int)A.size();   
    st.assign(4 * n, 0); 
    build(1, 0, n - 1);  
  }
 
  int rmq(pair<int,int> rg) {
      return rmq(1, 0, n - 1, rg.first, rg.second);
  }  

  int update_point(int idx, int new_value) {
    return update_point(1, 0, n - 1, idx, new_value);
  }
  
  int get(int idx)
  {
    return A[idx];
  }
};


int solve()
{
  int N, L;
  cin >> N >> L;
  vector<array<int,2>> PC(N);
  for(int i=0; i<N; i++) cin >> PC[i][0];
  for(int i=0; i<N; i++) cin >> PC[i][1];

  sort(PC.begin(), PC.end());

  vector<int> V(1000000001, 0);

  for(int i=0; i<N; i++)
    V[PC[i][0]] = max(V[PC[i][0]], PC[i][1]);

  auto st = SegmentTree(V);

  int sol=0;
  for(int i=0; i<N; i++)
  {
    sol = max(sol, PC[i][1]);
    sol = max(sol, PC[i][1] + V[st.rmq({PC[i][0], 1000000000})]);
  }

  return sol;
}

int main()
{
  int T;
  cin >> T;
  for(int i=0; i<T; i++) cout << solve() << std::endl;
  return 0;
}


