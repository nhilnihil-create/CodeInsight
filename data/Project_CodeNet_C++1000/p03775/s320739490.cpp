#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;
int func(int64_t x){
  int cnt=0;
   while(x){
     cnt++;
     x/=10;
   }
   return cnt;
}
int main() {
  int64_t N;
  cin>>N;
  int MIN=INF;
  for(int64_t i=1;i*i<=N;i++){
    if(N%i!=0){continue;}
    int64_t r=N/i;
    int m=max(func(i),func(r));
    chmin(MIN,m);
  }
  cout<<MIN<<endl;
  return 0;  
}