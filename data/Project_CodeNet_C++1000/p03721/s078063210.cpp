#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main() {
  // input
    int n;cin >> n;
    long k;cin >> k;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for(int i = 1;i < n + 1; i++) cin >> a[i] >> b[i];

  // compute 
    int ans = 0;
    vector<long> c(100100,0);

    for(int i = 1;i < n + 1; i++) {
        c[a[i]] += b[i];
    }

    for(int i = 1;i < 100100 ; i++) {
        if(c[i] < k){
            k = k - c[i];
        }else{
            cout << i << endl;
            return 0;
        }
    } 

  // output  

}
