#include <bits/stdc++.h>
#define INF 100000000000
#define MOD 1000000007
#define ll long long int
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()



using namespace std;
ll N;
ll K;
ll A[100010] = {};

ll get_gcd(ll a,ll b){
  if(b > a) swap(a,b);
  if(b==0) return a;
  ll tmp = b;
  b = a % b;
  a = tmp;
  return get_gcd(a,b);
}


int main() {
  cin>>N>>K;
  REP(i,N) cin>>A[i];
 // cout<<get_gcd(N,K);
 int g = A[0];
 bool flag = false;
 while(1){
   REP(i,N){
   g = get_gcd(g,A[i]);
   if(A[i] < K) continue;
   else flag = true;
 }
 if(!flag) {cout<<"IMPOSSIBLE"<<endl; return 0;}

 if(g == 1){cout<<"POSSIBLE"<<endl; return 0;}
 if(K % g != 0){cout<<"IMPOSSIBLE"<<endl; return 0;}
 REP(i,N) A[i] /= g;
 K /=g;

 }



  return 0;
}