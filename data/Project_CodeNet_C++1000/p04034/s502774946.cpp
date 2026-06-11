#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    //input
    int n,m; cin >> n >> m;
    vector<int> x(m + 1,0);
    vector<int> y(m + 1,0);
    for(int i = 1; i < m + 1; i++) cin >> x[i] >> y[i];

    //compute
    vector<int> p(n + 1,0);
    vector<int> b(n + 1,1);
    p[1] = 1;
    b[0] = 0;

    for(int i = 1; i < m + 1; ++i){
        if(p[x[i]] == 1){
            p[y[i]] = 1;
        }
        if(b[x[i]]== 1){
            p[x[i]] = 0;
        }
        b[x[i]] = b[x[i]] - 1;
        b[y[i]] = b[y[i]] + 1;     
    }

    //output
    cout << count(p.begin() + 1,p.begin() + n + 1,1) << endl;
}