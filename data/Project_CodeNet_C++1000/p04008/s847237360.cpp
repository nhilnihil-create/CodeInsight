# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <cstring>
# include <stdio.h>
# include <map>
# include <queue>

# define ll long long
# define pii pair<int,int>
# define FOR(a,b) for(int a=1; a<=b; a++)
# define REP(a,b) for(int a=0; a<b; a++)
# define FORU(a,b,c) for(int a=b; a<=c; a++)
# define FORD(a,b,c) for(int a=b; a>=c; a--)

using namespace std;

int N, K, nxt[100005];
vector<int> graf[100005];
int ans = 0;

int dfs(int u){
    int depth = 0;
    for(auto v : graf[u]){
        depth = max(depth, dfs(v));
    }

    if(depth == K-1 && nxt[u]!=1){
        ans++;
        return 0;
    }
    
    return depth+1;
}

int main(){

    ios :: sync_with_stdio(false);
    cin >> N >> K;
    FOR(i,N){
        cin >> nxt[i];
        if(i != 1) graf[nxt[i]].push_back(i);
        else{
            if(nxt[i] != 1) ans++;
            nxt[i] = 1;
        }
    }

    dfs(1);
    cout << ans << endl;

    return 0;
}