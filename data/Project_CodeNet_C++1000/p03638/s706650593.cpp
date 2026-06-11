#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int H,W;cin>>H>>W;
    int N;cin>>N;
    vector<int> a(N);
    REP(i,N)cin>>a[i];
    int now=0;
    vector<vector<int> > grid(H,vector<int>(W,0));
    REP(i,N){
        REP(j,a[i]){
            grid[now/W][now%W]=i+1;
            now++;
        }
    }
    for (int i=0;i<H;i+=2){
        reverse(all(grid[i]));
    }
    REP(i,H){
        REP(j,W){
            if(j)cout<<" ";
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    return 0;
}