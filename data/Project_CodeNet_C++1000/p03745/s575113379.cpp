#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 int N;
 cin>>N;
 vector<int>a(N);
 for(int i=0;i<N;i++){
   cin>>a[i];
 }
 int count=0;
 for(int i=0;i<N;i++){
   while(i<N-1&&a[i]==a[i+1]){i++;}
   if(i<N-1&&a[i+1]>a[i]){while(a[i+1]>=a[i]){i++;}}
   else if(i<N-1&&a[i+1]<a[i]){while(a[i+1]<=a[i]){i++;}}
   count++;
 }
 cout<<count<<endl;
  return 0;}