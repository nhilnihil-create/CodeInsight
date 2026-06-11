#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> x(n);
    rep(i,n) {
     cin >>x.at(i);
    }
    
    int count = 0;
    vector<int> a(8);
    
    rep(i,n) {
        if(x.at(i)<=3199){
        a.at(x.at(i)/400)++;
        }
        else{
            count++;
        }
     }
    int sum =0;
    rep(i,8) {
     if(a.at(i) >0) {
      sum++;
     }
    }
    
    if(sum >0) {
    cout << sum << ' ' << count+sum;
    } else {
     cout << 1 << ' ' << count;
    }
    
    
    }
