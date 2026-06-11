#include<bits/stdc++.h>
#define int long long
#define loop(i, a, b) for(int i = a; i < b; i++)
#define rep(i, a) loop(i, 0, a)
#define all(a) (a).begin(),(a).end()
using namespace std;
const int MOD = 1e9 + 7, INF = 1e9;
using vi = vector <int>;
using vvi = vector <vi>;
//g++ -std==c++14

signed main(){
    string s;
    cin >> s;
    string va = s;
    reverse(s.begin(), s.end());
    rep(i, s.size()){
        if(s[i] == 'b')s[i] = 'd';
        else if(s[i] == 'd')s[i] = 'b';
        else if(s[i] == 'p')s[i] = 'q';
        else if(s[i] == 'q')s[i] = 'p';
    }
    if(s == va)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}