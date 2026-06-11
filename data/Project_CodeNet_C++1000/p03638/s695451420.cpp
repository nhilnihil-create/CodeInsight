#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int h,w; cin >> h >> w;
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    Graph g(h, vector<int> (w,0));
    int tmp = 0;
    int now = 0;
    

    rep(i,h){
        rep(j,w){

            if(tmp < a[now]){
                g[i][j] = now + 1;
                tmp++;
            }

            if(tmp == a[now]){
                tmp = 0;
                now++;
            }
        }
    }

    rep(i,h){

        if(!(i & 1)){
            rep(j,w){
                cout << g[i][j] << " ";
            }
        }

        if(i & 1){
            for(int j = w-1;j >= 0; j--){
                cout << g[i][j] << " ";
            }
        }
        cout << endl;

    }

}