
#include<bits/stdc++.h>
#include<math.h>
#include <stdio.h>
#include<vector>
#include<deque>
#include<stdlib.h>
//#include <algorithm>
#include<set>
#include <limits>
#include<string>
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define ll long long
#define d_5 100000
#define d9_7 1000000007int N;

int main(void){
  ll n;
  cin>>n;
  vector<ll> p;
  rep(i,n){
    ll tp;
    cin >> tp;
    p.push_back(tp);
  }
  int sc=0;
  rep(i,n){
    if(p[i]==i+1){
      if(p[i+1]==i+2){
        swap(p[i],p[i+1]);
        sc++;
      }else{
        if(i==0){
          swap(p[i],p[i+1]);
          sc++;
        }else if(i==n-1){
          swap(p[i-1],p[i]);
          sc++;
        }else{
          if(p[i+1]<i+2){
            swap(p[i+1],p[i]);
            sc++;
          }else{
            swap(p[i],p[i-1]);
            sc++;
          }
        }
      }
    }
  }
  cout << sc;
	return 0;
}