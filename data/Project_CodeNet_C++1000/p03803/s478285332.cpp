#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    int a, b;
    cin >> a >> b;
    if(a == b) cout << "Draw" << endl;
    else{
        if(a == 1) cout << "Alice" << endl;
        else if(b == 1) cout << "Bob" << endl;
        else{
            if(a > b) cout << "Alice" << endl;
            else cout << "Bob" << endl;
        }
    } 

    return 0;
}