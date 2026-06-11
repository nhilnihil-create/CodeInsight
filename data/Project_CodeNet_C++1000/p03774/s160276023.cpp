#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main(){
    int n, m; cin >> n >> m;
    vector<P> pos, check;
    vector<int> ans;
    rep(i,n){
        int a, b; cin >> a >> b;
        pos.push_back(P(a,b));
    }
    rep(i,m){
        int c, d; cin >> c >> d;
        check.push_back(P(c,d));
    }
    rep(i,n){
        int min_d = INF;
        int index = -1;
        rep(j,m){
            int tmp = abs(pos[i].first - check[j].first) + abs(pos[i].second - check[j].second);
            if(min_d > tmp){
                index = j;
                min_d = tmp;
            }
        }
        ans.push_back(index+1);
    }
    for(auto e : ans){
        cout << e << endl;
    }
}