#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 100000

typedef long long ll;
typedef pair<ll,ll> P;

const double PI = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

int main(){
    int N,M,R;
    cin >> N >> M >> R;
    vector<ll> r(R);
    ll d[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    for(int i = 0; i < R; i++){
        ll a;
        cin >> a;
        a--;
        r[i] = a;
    }
    for(int i = 0; i < M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++) d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
        }
    }
    ll mincost = INF;
    sort(r.begin(),r.end());
    do{
        ll temp = 0;
        for(int i = 0; i < R - 1; i++){
            temp += d[r[i]][r[i+1]];
        }
        mincost = min(mincost,temp);
    }while(next_permutation(r.begin(),r.end()));
    cout << mincost << endl;
    return 0;
}
