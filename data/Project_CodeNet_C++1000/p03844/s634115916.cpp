#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    int a, b;
    char op;
    cin >> a >> op >> b;
    if(op == '+') cout << a + b << endl;
    else if(op == '-') cout << a - b << endl; 
    return 0;
}