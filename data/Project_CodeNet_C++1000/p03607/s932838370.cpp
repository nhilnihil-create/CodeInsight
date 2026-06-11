#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
  // input
    int n;cin >> n;
    vector<long> a(n + 1);
    for(int i = 1; i < n + 1; i++) cin >> a[i];

  // compute
    int counter = 1;
    int sum = 0;
    int ans = 0;
  	sort(a.rbegin(),a.rend());

    for(int i = 1; i < n + 1; i++) {
        if( a[i - 1] == a[i]){
           counter += 1;
        }else{
           sum += counter % 2;
           counter = 1;
        }
    }

    ans = sum;

  // output  
    cout << ans << endl;
}