#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define p(s) cout<<(s)<<endl
#define REP(i,n,N) for(int i=n;i<N;i++)
#define RREP(i,n,N) for(int i=N-1;i>=n;i--)
#define CK(n,a,b) ((a)<=(n)&&(n)<(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const int inf = 1e9;
const ll INF = 1e18;
const int NODE_SIZE = 310;

ll N;  //グラフのノードの数
ll d[NODE_SIZE][NODE_SIZE];  //ノード接続関係 兼 最短距離(任意の二点間)
ll b[NODE_SIZE][NODE_SIZE];
bool f[NODE_SIZE][NODE_SIZE];
ll warshall_floyd(){
    ll sum=0;
    REP(i,0,N) {
        REP(j,0,N) {
            sum += d[i][j];
        }
    }
    sum/=2;
    REP(k,0,N){
        REP(i,0,N){
            if(d[i][k] == INF || i==k) continue;
            REP(j,0,N){
                if(d[k][j] == INF || j==k) continue;
                //d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                if(b[i][j] > d[i][k] + d[k][j]){
                    return -1;
                }else if(b[i][j] == d[i][k] + d[k][j] && !f[i][j]){
                    sum -= b[i][j];
                    f[i][j] = f[j][i] = true;
                }
            }
        }
    }

    return sum;
}

int main(){
    cin>>N;

    REP(i,0,N){
        REP(j,0,N){
            if(i==j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    REP(i,0,N){
        REP(j,0,N){
            cin>>b[i][j];
            d[i][j]=b[i][j];
        }
    }

    p(warshall_floyd());
    return 0;
}
