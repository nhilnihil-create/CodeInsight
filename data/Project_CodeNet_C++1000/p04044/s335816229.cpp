#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    for(int i = 0; i < n; i++){
        cout << s[i];
    }
    cout << endl;
    
    return 0;
}