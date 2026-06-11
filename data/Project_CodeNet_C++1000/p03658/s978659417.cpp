#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int x[110];
int y[110];

int func(int y){
  int sum=0;
  int x=y;
  while(x!=0){
    sum+=x%10;
    x/=10;
  }
  return sum;
}
int main() {
 int N,K;
 cin>>N>>K;
 vector<int>l(N);
 for(int i=0;i<N;i++){
   cin>>l.at(i);}
 sort(l.begin(),l.end());
 reverse(l.begin(),l.end());
 int ans=0;
 for(int i=0;i<K;i++){
  ans+=l.at(i);
 }
 cout<<ans<<endl;
  return 0;
}