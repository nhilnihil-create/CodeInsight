// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>


using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);i++)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}


int main() {
  int n;cin>>n;
  int sum=0;
  int temp;
  int ans=0;
  vector<int> a(n,0);
  rep(i,n){
    cin>>temp;
    a[i]=temp;
    sum+=temp;
  }
  int mean = floor(float (sum)/n+0.5);
  rep(i,n){
    ans+=(a[i]-mean)*(a[i]-mean);
  }
  cout<<ans<<endl;
}
