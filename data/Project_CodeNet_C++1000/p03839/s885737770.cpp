
#include<bits/stdc++.h>
#include<math.h>
#include <stdio.h>
#include<vector>
#include<deque>
#include<stdlib.h>
//#include <algorithm>
#include<set>
#include <limits>
#include<iomanip>
#include<string>
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define ll long long
#define d_5 100000
#define d9_7 1000000007
int main(void){
  ll n,k;
  cin >> n>>k;
  vector<ll> a(n,0);
  ll tmp;
  rep(i,n){
    cin>>a[i];
  }
  ll sum=0;
  ll msum=0;
  rep(i,k){
    msum+=a[i];
  }
  if(n==k){
    cout<<max((ll)0,msum);
    return 0;
  }
  ll rsum=0;
  rep(i,n-k){
    rsum+=max((ll)0,a[k+i]);
  }
  ll lsum=0;
  rep(i,n-k){
    msum-=a[i];
    msum+=a[k+i];
    if(a[i]>0){
      lsum+=a[i];
    }
    if(a[i+k]>0){
      rsum-=a[i+k];
    }
    sum=max(sum,max(msum,(ll)0)+rsum+lsum);
  }
  cout<<sum;
	return 0;
}