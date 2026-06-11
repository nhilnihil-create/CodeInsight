#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for(ll i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define vec vector
typedef long long ll;
const int INF = 1001001001;

/*　<<stringで読み込んだ数列を一桁ずつint型へ変換>>
 
    string str;
    int N[桁数];
 
    cin >> str;
 
    for (int i = 0; i < 桁数; ++i) {
 
        N[i] = (int)(str[i] - '0');  //str[i]　はchar型なのでchar→intへ変換
 
        //cout << N[i] << endl;  //確認のため表示
    }
*/
 


///////////////////////////////////////////////////////////////////////////


int main() {
    
    string s;
    cin >> s;
    int size;
    size = s.size();

    ll ans = 0;
    rep(i,1<<size-1){
        string rem = s;
        int cnt = 1;
        rep(j,size-1){
            if(i>>j&1){
                ll target = stoll(rem.substr(0,cnt));
                ans += target;
                rem = rem.substr(cnt);
                cnt = 1;
            }
            else cnt++;
        }
        if(rem.size()) ans += stoll(rem);
    }
        cout << ans << endl;
}