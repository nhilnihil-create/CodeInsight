#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ',') cout << " ";
        else cout << s[i];
    }
    cout << endl;

    return 0;
}