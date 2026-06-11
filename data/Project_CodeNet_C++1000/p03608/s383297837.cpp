#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
#define MAXA 1001
#define MAXB 1001
#define MAXH 1000000001
#define MAXW 301
#define INF (1 << 30)
#define MAXN 100001
#define MAXM 100001
#define MAXK 100002
#define MAXV 201
#define MAXP 1000001
#define MOD 1000000007
#define EPS (1e-10)
typedef long long ll;

int V, M, R;
int order[8];
int d[MAXV][MAXV];

void warshall_floyd(){
    for(int k = 0;k < V;k++){
        for(int i = 0;i < V;i++){
            if(d[i][k] < 0) continue;
            for(int j = 0;j < V;j++){
                if(d[k][j] < 0) continue;

                if(d[i][j] < 0) d[i][j] = d[i][k] + d[k][j];
                else d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }     
        }
    }
}


int main(){
    memset(d, -1, sizeof(d));
    cin >> V >> M >> R;
    for(int i = 0;i < R;i++){
        cin >> order[i];
    }
    int to, from, cost;
    for(int i = 0;i < M;i++){
        cin >> to >> from >> cost;
        to--;from--;
        d[to][from] = cost;
        d[from][to] = cost;
    }
    sort(order, order + R);
    warshall_floyd();
    int ans = INF, sum;
    do{
        sum = 0;
        
        for(int i = 0;i < R - 1;i++){
            sum += d[order[i] - 1][order[i + 1] - 1];
        }
        ans = min(ans, sum);
    }while(next_permutation(order, order + R));


    printf("%d\n", ans);
    return 0;
}