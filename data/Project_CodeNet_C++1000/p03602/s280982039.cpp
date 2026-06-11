#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL INF = 1e10;

int main(){
    int N;
    cin >> N;
    vector<vector<LL>> a(N, vector<LL>(N, INF)), d(N, vector<LL>(N, INF));
    bool f = false;
    for(int i = 0;i < N;i++)   for(int j = 0;j < N;j++)   cin >> a[i][j];
    for(int k = 0;k < N;k++){
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                d[i][j] = min(a[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    LL ans = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(d[i][j] < a[i][j]){
                f = true;
            }else{
                bool ff = true;
                for(int k = 0;k < N;k++){
                    if(k == i || k == j)    continue;
                    if(d[i][k]+d[k][j] == a[i][j])  ff = false;
                }
                if(ff)  ans += a[i][j];
            }
        }
    }
    if(f)   cout << -1 << endl;
    else    cout << ans/2 << endl;
}