#include<bits/stdc++.h>

using namespace std;
const int Sz = 1e6 + 5;
int a[Sz],b[Sz];
string s, t;
int q, l, r, l2, r2;
int32_t main(){
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    a[0] = 0;
    b[0] = 0;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == 'A') a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1] + 2;
    }
    for(int i = 1; i < t.size(); i++){
        if(t[i] == 'A') b[i] = b[i - 1] + 1;
        else b[i] = b[i - 1] + 2;
    }
    cin >> q;
    while(q--){
        cin >> l >> r >> l2 >> r2;
        int x = (a[r] - a[l - 1]) % 3;
        int y = (b[r2] - b[l2 - 1]) % 3;
        if(abs(x) == abs(y)) cout << "YES\n";
        else cout << "NO\n";
        //cerr << x << " " << y << "\n";
    }
    return 0;
}
