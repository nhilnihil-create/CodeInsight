#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string s;
    cin >> s;
    for(char c = 'a'; c <= 'z'; c++){
        if(s.find(c) == string::npos){
            cout << c << endl;
            return 0;
        }
    }
    cout << "None" << endl;

    return 0;
}