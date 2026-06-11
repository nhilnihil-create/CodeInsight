#include <bits/stdc++.h>
using namespace std;
#define REP(i,x,n) for(int i = x; i < n; i++)
#define MAX 100
#define INF 1000000001

int n;
vector<int> adj[114514];
int d[2][114514];

// char X[100][100];
// int dp[1000000001];

void dfs(int peek, int current, int depth, int w) {
    // int i;
    
    d[w][peek] = depth;
    
    REP(i,0,adj[peek].size()) {
        if (adj[peek][i] == current) continue;
        
        dfs(adj[peek][i],peek,depth+1,w);
    }
}


int main(void){
    cin >> n;
    REP(i,0,n-1) {
        int a,b;
        cin >> a >> b;
        
        a--; 
        b--;
        
        // cout << a << b << endl;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(0,-1,0,0);
    dfs(n-1,-1,0,1);


    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < n; i++) {
        if (d[0][i] <= d[1][i]) {
            c1++;
        } else {
            c2++;
        }
    }
    
    if (c1 > c2) {
        puts("Fennec");
    } else {
        puts("Snuke");
    }
    
    return 0;

}