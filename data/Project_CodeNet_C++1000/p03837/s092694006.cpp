#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 105;

const int mod = 1e9+7;

int n;
int m;
int dist[N][N];
vector < pair < pair < int , int > , int > > ed;

int main() {
    memset(dist , '?' , sizeof dist);
    scanf("%d%d" , &n , &m);
    for(int i = 1; i <= n; i++)
        dist[i][i] = 0;
    for(int i = 1; i <= m; i++){
        int a, b , c;
        scanf("%d%d%d" , &a , &b , &c);
        ed.push_back({{a , b} , c});
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
            }
        }
    }
    int cnt = 0;
    for(auto e : ed){
        int a = e.first.first;
        int b = e.first.second;
        int c = e.second;
        bool yes = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][j] == dist[i][a] + c + dist[b][j]){
                    //printf("%d %d %d\n" , i , j , dist[i][j]);
                    yes = 0;
                }
            }
        }
        if(!yes){
            cnt++;
        }
    }
    printf("%d\n" , m - cnt);
    return 0;
}
