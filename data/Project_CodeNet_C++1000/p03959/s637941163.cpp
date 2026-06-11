
#include<bits/stdc++.h>
#include<math.h>
#include <stdio.h>
#include<vector>
#include<deque>
#include<stdlib.h>
#include <algorithm>
#include<set>
#include<map>
#include <limits>
#include<iomanip>
#include<string>
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define ll long long
#define d_2 100000
#define d9_7 1000000007
int main(void){
  ll n;
  cin >> n;
  vector<ll> t(n);
  vector<ll> a(n);
  rep(i,n){
    cin>>t[i];
  }
  rep(i,n){
    cin>>a[i];
  }
  ll ans=0;
  if(n==1&&a[0]!=t[n-1]){
    cout<<0<<endl;
    return 0;
  }
  if(n==2){
    if(a[0]==a[1]  ||  t[0]==t[1]){
      cout<<1<<endl;
    }else{
      cout<<0<<endl;
    }
    return 0;
  }
  if(a[0]!=t[n-1]){
    cout<<0<<endl;
    return 0;
  }
  rep(i,n){
    if(i==0){
      ans=1;
      continue;
    }else if(i==n-1){
      continue;
    }
    ll aa=(ll)min(a[i],t[i]);
    if(t[i-1]<t[i]||a[i+1]<a[i]){
      aa=1;
    }
    if(i>n/2+1){
      if(t[i-1]<t[i]){
        if(a[n-1-i]<t[i]){
          cout<<"0"<<endl;
          return 0;
        }
      }
    }else if(i<n/2){
      if(a[i+1]<a[i]){
        if(t[n-1-i]<a[i]){
          cout<<"0"<<endl;
          return 0;
        }
      }
    }
    if(t[i-1]<t[i]){
      if(t[i]>a[i]){
        cout<<"0"<<endl;
        return 0;
      }
    }
    if(a[i+1]<a[i]){
      if(t[i]<a[i]){
        cout<<"0"<<endl;
        return 0;
      }
    }
    ans=(aa*ans)%d9_7;
  }
  cout<<ans%d9_7<<endl;
  return 0;
}