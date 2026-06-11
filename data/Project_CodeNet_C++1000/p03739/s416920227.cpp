#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
int main () {
    ll n ;
    cin >> n ;
    ll A[n] ;
    ll a,now1=0,cnt1=0,now2=0,cnt2=0;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i] ;
    }
    rep(i,n) {
    now1 += A[i];
    now2 += A[i];
    if (now1<=0) {
      cnt1+=abs(now1)+1;now1=1;
    }
    if (now2>=0) {
      cnt2+=abs(now2)+1;now2=-1;
    }
    swap(now1,now2);swap(cnt1,cnt2);
    }
    cout << min(cnt1,cnt2) << endl;
    return 0 ;
}

 
