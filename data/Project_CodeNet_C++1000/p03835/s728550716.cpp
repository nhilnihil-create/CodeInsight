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
    int k, s;
    cin >> k >> s;

    int ans = 0;
    for(int x=0; x<=k; ++x){
        for(int y=0; y<=k; ++y){
            int z = s - x - y;
            if(z>=0 && z<=k) ++ans;
        }
    }

    cout(ans);

    return 0;
}