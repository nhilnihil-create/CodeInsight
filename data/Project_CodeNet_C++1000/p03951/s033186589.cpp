#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int cnt = 0;
    int i = 0;
    for(int i = 1; i <= n; i++){
        string tmps = s.substr(n-i,i);
        string tmpt = t.substr(0,i);
        if(tmps == tmpt) cnt = i;
    } 
    cout << 2*n-cnt << endl;
}