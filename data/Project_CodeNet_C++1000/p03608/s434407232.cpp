#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define ALL(a) a.begin(), a.end()
static const int INF = 1000000007;
const ll MOD = (1e+9) + 7;
typedef pair<int, int> P;

int d[205][205];

int main(){
    int n,m,r;
    cin >> n>> m>> r;
    vector<int> vec(r);
    rep(i,r){
        int R;
        cin >> R;
        R--;
        vec[i]=R;
    }
    sort(ALL(vec));
    rep(i,n)rep(j,n)d[i][j]=INF;
    rep(i,n)d[i][i]=0;
    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        d[a][b]=c;
        d[b][a]=c;
    }
    rep(k,n)rep(i,n)rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    int ans=INF;
    do{
        int temp=0;
        rep(i,r-1){
            temp+=d[vec[i]][vec[i+1]];
        }
        ans=min(temp,ans);
    }while(next_permutation(ALL(vec)));
    cout<<ans<<endl;
    return 0;
}