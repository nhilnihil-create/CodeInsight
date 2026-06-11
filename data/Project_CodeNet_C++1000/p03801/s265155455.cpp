#include<bits/stdc++.h>
using namespace std;
void rd(long long &x){
  int k, m=0;
  x=0;
  for(;;){
    k = getchar_unlocked();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = getchar_unlocked();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
void wt_L(long long x){
  char f[20];
  int m=0, s=0;
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    putchar_unlocked('-');
  }
  while(s--){
    putchar_unlocked(f[s]+'0');
  }
}
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
long long A[100010], N, ans[100010];
int main(){
  int i, left, stk;
  pair<int, int> last;
  vector<pair<int, int>> pq;
  rd(N);
  {
    int PiIOrLma;
    for(PiIOrLma=0;PiIOrLma<N;PiIOrLma++){
      rd(A[PiIOrLma]);
    }
  }
  pq.reserve(N);
  for(i=0;i<N;i++){
    pq.emplace_back(A[i], i);
  }
  pq.emplace_back(0, 0);
  sort(pq.begin(), pq.end());
  reverse(pq.begin(), pq.end());
  stk = 0;
  left = pq[0].second;
  for(i=0;i<N;i++){
    left =min_L(left, pq[i].second);
    ans[left] += (long long)(i+1)*(pq[i].first - pq[i+1].first);
  }
  {
    int FJNsjZ7B;
    for(FJNsjZ7B=0;FJNsjZ7B<N;FJNsjZ7B++){
      wt_L(ans[FJNsjZ7B]);
      putchar_unlocked('\n');
    }
  }
  return 0;
}
// cLay varsion 20180208-1

// --- original code ---
// ll N;
// ll A[100010];
// ll ans[100010];
// 
// {
//     vector<pair<int, int>> pq;
//     pair<int, int> last;
//     int stk, left;
//     
//     rd(N, A(N));
//     pq.reserve(N);
//     REP(i, N) pq.emplace_back(A[i], i);
//     pq.emplace_back(0, 0);
//     sort(pq.begin(), pq.end()); // greater...
//     reverse(pq.begin(), pq.end());
//     
//     stk = 0;
//     left = pq[0].second;
//     
//     REP(i, N) {
//         left = min(left, pq[i].second);
//         ans[left] += (ll)(i+1)*(pq[i].first - pq[i+1].first);
//     }
//     
//     wtLn(ans(N));
// }