#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  // input
    int n,m;cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> c(m + 1);
    vector<int> d(m + 1);

    for(int i = 1;i < n + 1; i++) {
        cin >> a[i] >> b[i];
    }
    for(int i = 1;i < m + 1; i++) {
        cin >> c[i] >> d[i];
    }

  // compute 
    vector<int> ans(n + 1);
    vector<int> mi(n + 1);
    vector<vector<int>> mk(n + 1, vector<int>(m + 1));
    for(int i = 1;i < n + 1 ; i++) {
        for(int j = 1; j < m + 1; j++){
            mk[i][j] = abs(a[i] - c[j]) + abs(b[i] - d[j]);
        } 
    }

    for(int i = 1;i < n + 1 ; i++){
        ans[i] = 1;
        mi[i] = mk[i][1];
    }

    for(int i = 1;i < n + 1 ; i++) {
        for(int j = 1; j < m + 1; j++){
            if(mk[i][j] < mi[i]){
                ans[i] = j;
                mi[i] = mk[i][j];
            }
        } 
    }

  // output  
    for(int i = 1;i < n + 1; i++) {
        cout << ans[i] << endl;
    }

}