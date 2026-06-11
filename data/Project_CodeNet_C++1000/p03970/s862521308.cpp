#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int cnt = 0;
    string s;
    cin >> s;
    string t = "CODEFESTIVAL2016";
    for(int i=0;i<16;i++){
        if(s[i] != t[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}