#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<(x)<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Mat = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5+10;

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    for(int i=1; i<=b; ++i){
        if((a*i)%b==c){
            cout("YES");
            return 0;
        }
    }
    cout("NO");
    return 0;
}






