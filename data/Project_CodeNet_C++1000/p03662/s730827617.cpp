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

#define CK(N, A, B) (A <= N && N < B)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long LLINF = 1e18;

using namespace std;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int dy8[] = {0,1,1,1,0,-1,-1,-1};
int dx8[] = {1,1,0,-1,-1,-1,0,1};

/*==================================================*/
/*variable*/
int N;
int a, b;
vector<int> v[100010];
int d0[100010];
int dn[100010];
/*==================================================*/
/*function*/
void dfs0(int node, int step){
    if(d0[node] <= step) return;
    d0[node] = step;

    REP(i,0,v[node].size()){
        dfs0(v[node][i], step+1);
    }
}
void dfsn(int node, int step){
    if(dn[node] <= step) return;
    dn[node] = step;

    REP(i,0,v[node].size()){
        dfsn(v[node][i], step+1);
    }
}

/*==================================================*/

int main() {
    cin>>N;
    REP(i,0,N-1){
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    REP(i,0,N) d0[i] = INF;
    REP(i,0,N) dn[i] = INF;
    dfs0(0,0);
    dfsn(N-1,0);

    int b = 0, w = 0;
    REP(i,0,N){
        if(d0[i] <= dn[i]){
            b++;
        }else{
            w++;
        }
    }

    if(b > w){
        cout<<"Fennec"<<endl;
    }else{
        cout<<"Snuke"<<endl;
    }

    return 0;
}
