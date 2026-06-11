#include<bits/stdc++.h>
using namespace std;


const int N = 505, INF = 1e9 + 7;
const char colors[2][2] = {{'R', 'Y'}, {'G', 'B'}};


int n, m, d;
char cl[N][N];

inline pair < int, int > tr(int x, int y){
    return make_pair(x + y, x - y);
}
inline pair < int, int > inv_tr(int x, int y){
    if((x + y) % 2 || (x - y) % 2){
        return make_pair(-1, -1);
    }
    return make_pair((x + y) / 2, (x - y) / 2);
}
inline bool check(pair < int, int > a){
    return 1 <= a.first && a.first <= n && 1 <= a.second && a.second <= m;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> d;
    vector < pair < int, int > > q;
    q.push_back(tr(1, 1));
    q.push_back(tr(n, 1));
    q.push_back(tr(1, m));
    q.push_back(tr(n, m));
    int mnX = +INF, mnY = +INF,
        mxX = -INF, mxY = -INF;
    for(auto it : q){
        mnX = min(mnX, it.first);
        mnY = min(mnY, it.second);
        mxX = max(mxX, it.first);
        mxY = max(mxY, it.second);
    }
    bool cl1 = 0, cl2 = 0;
    for(int i = mnX; i <= mxX; i += d){
        for(int j = mnY; j <= mxY; j += d){
            for(int ii = i; ii <= i + d - 1; ii++){
                for(int jj = j; jj <= j + d - 1; jj++){
                    auto it = inv_tr(ii, jj);
                    if(check(it)){
                        cl[it.first][it.second] = colors[cl1][cl2];
                    }
                }
            }
            cl2 ^= 1;
        }
        cl1 ^= 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << cl[i][j];
        }
        cout << "\n";
    }
}
