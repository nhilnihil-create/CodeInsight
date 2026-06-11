#include <bits/stdc++.h>

using namespace std;

int main() {
    int n ; cin >> n;
    vector<int>p(n);
    for(int& i : p)cin >> i;
    int sum = accumulate(p.begin() , p.end() , 0);
    int m ; cin >> m; 
    for(int i = 0 ; i < m; ++i){
        int x , v; cin >> x >> v;
        cout << sum - p[x -1] + v << endl;
    }
    
}