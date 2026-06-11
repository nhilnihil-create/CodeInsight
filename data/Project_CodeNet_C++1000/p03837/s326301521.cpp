#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define pb push_back
const int maxn = 110;
const int maxn2 = 1100;
const int INF32 = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7 = 1'000'000'007;
const int MOD9 = 1'000'000'009;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};

int n, m;
int a[maxn2], b[maxn2], c[maxn2]; 
int dist[maxn][maxn]; 

int main(){
    cin >> n >> m;

    //Floyd-Warshall Initialize
    rep(i,n){
    	rep(j,n){
            dist[i][j] = INF32;
        }
        dist[i][i] = 0;
    }

    rep(i,m){
        cin >> a[i] >> b[i] >> c[i];
        --a[i], --b[i];
        dist[a[i]][b[i]] = c[i];
        dist[b[i]][a[i]] = c[i];
    }

    //Floyd-Warshall
    rep(k,n)rep(i,n)rep(j,n){
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    }

    int cnt = 0;
    rep(i,m){
        if(c[i] > dist[a[i]][b[i]]) cnt++;
    }
    cout << cnt << endl;
}