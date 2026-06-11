#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    char a, b;
    cin >> a >> b;
    if(a == 'H'){
        if(b == 'H') cout << 'H' << endl;
        else cout << 'D' << endl;
    }
    else{
        if(b == 'H') cout << 'D' << endl;
        else cout << 'H' << endl;        
    }

    return 0;
}