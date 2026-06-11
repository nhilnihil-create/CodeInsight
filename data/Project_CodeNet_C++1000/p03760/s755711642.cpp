#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string o, e;
    cin >> o >> e;

    int size;
    if(o.size() < e.size()) size = e.size();
    else size = o.size();

    for(int i = 0; i < size; i++){
        if(i < o.size()) cout << o[i];
        if(i < e.size()) cout << e[i];
    }
    cout << endl;
    
    return 0;
}