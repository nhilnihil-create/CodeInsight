#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    string s;
    cin >> s;
    int cnt = 1;
    s.erase(s.size()-2);
    while(1){
        int mid = s.size()/2; /* 後半の開始文字 */
        string tmp, tmp_2;
        tmp = s.substr(mid);
        tmp_2 = tmp + tmp;
        if(tmp_2 == s){
            cout << tmp_2.length() << endl;
            /* cout << tmp << endl;
            cout << tmp_2 << endl; */
            break;
        }
        cnt++;
        s.erase(s.size()-2);
    }
    return 0;
}