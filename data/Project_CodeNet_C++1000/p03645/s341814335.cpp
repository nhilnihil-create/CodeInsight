#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,m;cin >> n >> m;
    vector<int> one;
    vector<bool> ns(200000,false);
    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        if(a==1){
            one.push_back(b);
        }
        if(b==n){
            ns[a-1]=true;
        }
    }
    for(int i = 0; i < one.size(); i++) {
        if(ns[one[i]-1]){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
   
}