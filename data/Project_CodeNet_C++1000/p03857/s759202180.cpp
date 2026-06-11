#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iterator>

using namespace std;
#define int long long
/*                      */    //#undef int
#define INF 1000000009
#define INFL 1000000000000000018ll
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define mk make_pair
typedef pair<int, int> PA;
typedef priority_queue<int> PQ;
typedef priority_queue<PA, vector<PA>, greater<PA> >PQG;

int N, K, L;
int par[2][200005], rankk[2][200005];

void init()
{
    for(int i = 0; i <= N; i++){
        par[0][i] = i;
        par[1][i] = i;
    }
}

int root(int x, int e)
{
    if(par[e][x] == x){
        return x;
    }
    else{
        return par[e][x] = root(par[e][x], e);
    }
}

void unite(int x, int y, int e)
{
    x = root(x, e), y = root(y, e);
    if(x == y)return;

    if(rankk[e][x] < rankk[e][y]){
        par[e][x] = y;
    }
    else {
        par[e][y] = x;
        if(rankk[e][x] == rankk[e][y]){
            rankk[e][x]++;
        }
    }
}

bool same(int x, int y, int e)
{
    return root(x, e) == root(y, e);
}

map<PA, int> mp;

signed main()
{
    cin >> N >> K >> L;
    init();
    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        unite(a, b, 0);
    }
    for(int i = 0; i < L; i++){
        int a, b;
        cin >> a >> b;
        unite(a, b, 1);
    }
    for(int i = 1; i <= N; i++){
        int x = root(i, 0), y = root(i, 1);
        mp[mk(x, y)]++;
        //printf("PA %lld %lld\n", x, y);
    }
    for(int i = 1; i <= N; i++){
        int x = root(i, 0), y = root(i, 1);
        printf("%lld", mp[mk(x, y)]);
        if(i < N) printf(" ");
    }
    printf("\n");

    return 0;
}
