#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 305;
bool ban[N];
int cnt[N];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            cin >> a[i][j];
            a[i][j] -- ;
        }
    }
    int answ = n;
    for(int i = 0 ; i  < m ; i ++ ){
        vector<pii> costl;
        for(int j = 0 ; j < m ; j ++ )
            cnt[j] = 0;
        for(int j = 0 ; j < n; j ++ ){
            for(int t = 0; t < m ; t ++ ){
                if(ban[a[j][t]] == false){
                    cnt[a[j][t]] ++ ;
                    break;
                }
            }
        }
        for(int j = 0 ; j < m ; j ++ )
            if(!ban[j])
                costl.push_back(mp(cnt[j], j));
        sort(costl.begin(), costl.end());
        reverse(costl.begin(), costl.end());
        answ = min(answ, costl[0].fi);
        ban[costl[0].se] = true;
    }
    cout << answ;
    return 0;
}