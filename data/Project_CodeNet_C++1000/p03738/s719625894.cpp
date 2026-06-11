#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string a, b;
    cin >> a >> b;
    int a_len, b_len;
    a_len = a.size();
    b_len = b.size();

    if(a_len > b_len) cout << "GREATER" << endl;
    else if(a_len < b_len) cout << "LESS" << endl;
    else{
        if(a > b) cout << "GREATER" << endl;
        else if(a < b) cout << "LESS" << endl;
        else cout << "EQUAL" << endl;
    }

    return 0;
}