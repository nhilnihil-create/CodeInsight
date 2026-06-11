#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>pppp(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p;
}
 
int main() {
 int n;
 cin>>n;
 vector<int>a(n),b;
 for(int i=0;i<n;i++){
   cin>>a[i];
 }
 for(int i=n-1;i>=0;i--){
   if(i%2==(n-1)%2){b.push_back(a[i]);}
 } 
 for(int i=0;i<n;i++){
   if(i%2!=(n-1)%2){b.push_back(a[i]);}
 } 
 for(int i=0;i<n;i++){
   cout<<b[i];
   if(i<n-1){cout<<" ";}
 }
 cout<<endl;
  return 0;
}