#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
using namespace std;

int main() {
    //input
    int n,m; cin >> n >> m;
    vector<int> a(m + 1);
    vector<int> b(m + 1);
    for(int i = 1; i < m + 1; i++) cin >> a[i] >> b[i];

    //compute
    set<int> s1,s2;
    for(int i = 1; i < m + 1; i++) {
        if(a[i] == 1){
            s1.insert(b[i]);
            }
        if(b[i] == n){
            s2.insert(a[i]);
            }
    }
  
    //output
    for(int i = 1; i < n + 1; i++) {
        if((s1.count(i) == 1) && (s2.count(i) == 1)){
          cout << "POSSIBLE" << endl;
          return 0;
        }else{
        }
    }
    cout << "IMPOSSIBLE" << endl;
}