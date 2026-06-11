#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<utility>
#include <map>
#include <set>

using namespace std;

#define REP(i,x) for(int i=0; i<(int)(x); i++)       // 0 <= i < x
#define REPS(i,x) for(int i=1; i<=(int)(x); i++)     // 0 < i <= x
#define RREP(i,x) for(int i=((int)(x)-1); i>=0; i--) // x > i >= 0
#define RREPS(i,x) for(int i=((int)(x)); i>0; i--)   // x >= i > 0
#define INF 100000000

typedef long long ll;
typedef pair<int, int> P;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void){
    int N;
    cin >> N;
    int dist[N][N];
    REP(i, N){
        REP(j, N){
            cin >> dist[i][j];
        }
    }

    ll res = 0;
    REP(i, N - 1){
        for(int j = i + 1; j < N; j++){
            bool x = true;
            REP(k, N){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    cout << "-1\n";
                    return 0;
                }else if(dist[i][j] == dist[i][k] + dist[k][j] && k!=i && k!=j){
                    x = false;
                    break;
                }
            }

            if(x){
                res += dist[i][j];
            }
        }
    }

    cout << res << endl;
    return 0;
}
