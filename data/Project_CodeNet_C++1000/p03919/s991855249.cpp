
#include<bits/stdc++.h>
//#define int long long
#define loop(i, a, b) for(int i = a; i < b; i++)
#define rep(i, a) loop(i, 0, a)
#define all(a) (a).begin(),(a).end()
using namespace std;
const int MOD = 1e9 + 7, INF = 1e9;
using vi = vector <int>;
using vvi = vector <vi>;
//g++ -std==c++14
 
int main(){
    int h, w;
    cin >> h >> w;
    char yoko[26];
    rep(i, 26)yoko[i] = 'A' + i;
    string s_in;
    string ans = "";
    rep(i, h)rep(j, w){
        cin >> s_in;
        if(s_in == "snuke"){
            ans += yoko[j];
            ans += to_string(i + 1);
        }
    }
    cout << ans << endl;
}