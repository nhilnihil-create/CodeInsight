
#include<bits/stdc++.h>
#include<math.h>
#include <stdio.h>
#include<vector>
#include<deque>
#include<stdlib.h>
#include <algorithm>
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
  ll n,t;
  cin >> n>>t;
  vector<ll> a(n);
  rep(i,n){
    cin>>a[i];
  }
  vector<ll> amin(n,a[0]);//ここから、ここを含む左にあるものでもっとも小さい値
  vector<ll> amax(n,a[n-1]);//ここから、ここを含む左にあるものでもっとも大きい値
  rep(i,n-1){
    if(a[i+1]<amin[i]){
      amin[i+1]=a[i+1];
    }else{
      amin[i+1]=amin[i];
    }
  }
  rep(i,n-1){
    if(a[n-1-(i+1)]>amax[n-1-i]){
      amax[n-1-(i+1)]=a[n-1-(i+1)];
    }else{
      amax[n-1-(i+1)]=amin[n-1-i];
    }
  }
  ll diff=0;
  rep(i,n){
    diff=max(amax[i]-amin[i],diff);
  }
  ll tmpmin=llMAX;
  ll tmpmax=-1;
  int cnt=0;
  int stack=0;
  rep(i,n){
    /*tmpmin=min(a[i],tmpmin);
    tmpmax=max(a[i],tmpmax);*/
    if(stack==0){
      tmpmin=a[i];
      tmpmax=a[i];
      stack=1;
    }else{
      if(tmpmin>a[i]){
        tmpmin=a[i];
        tmpmax=a[i];
        stack=1;
      }else if(tmpmin==a[i]){
        stack++;
      }else{
        tmpmax=max(tmpmax,a[i]);
      }
      if(tmpmax-tmpmin==diff){
        cnt++;
        stack--;
      }else if(tmpmax-tmpmin>diff){
        cout<<"algorithm ERROR"<<endl;
      }
    }
  }
  cout<<cnt <<endl;
  return 0;
}