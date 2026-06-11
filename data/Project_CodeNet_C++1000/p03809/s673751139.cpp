#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vii         vector<pair<int,int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define endl '\n'
#define int long long int
using namespace std;
vi adj[(int)1e5 + 5];
int vals[(int)1e5 + 5];
bool fail = false;
int check(int cur, int P){
   //debug(cur); 
    int ans =0;
    int sum  =0;
    int mx = 0;
    int childs = 0;
    for(int child: adj[cur]){
        if(child == P)continue;
        int pass = check(child, cur);
        sum += pass;
        mx = max(mx, pass);
        childs++;
        if(fail)return 0;
    }
    // sum - inner == vals[cur]
    if(childs == 0)return vals[cur];

    int mxPaths = vals[cur];
    if(mx > sum/2){
        mxPaths=  min(mxPaths, sum - mx);
    }
    mxPaths = min(mxPaths, sum/2);
    int inner = sum - vals[cur];
    if(inner > mxPaths)fail = true;
    if(inner < 0)fail = true;
//    debug(cur);
 //   debug(sum);
  //  debug(sum - inner*2);
    return sum - inner*2;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int n;cin >> n;
    FOR(i, n)cin >> vals[i];
    int x,y;
    FOR(i, n-1){
        cin >>  x >> y;
        x--, y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    FOR(i, n)
       if(adj[i].size() > 1){
        int pass =check(i, -1);
        if(pass != 0)fail = true;
        cout << (!fail ? "YES" : "NO") << endl;
        return 0;
    }
    cout << (vals[0] == vals[1] ? "YES" : "NO") << endl;

}


