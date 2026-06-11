#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define f first
#define se second
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L


typedef long long ll;

const ll MOD =1e9+7;


char grid1[51][51];
char grid2[51][51];

void solve(){
    int N,M;
    cin>>N>>M;
    int cnt=0;
    for(int i=0;i<N;++i)cin>>grid1[i];
    for(int i=0;i<M;++i)cin>>grid2[i];
    bool flag=0;
    for(int row1=0;row1<=N-M;++row1){
        for(int col1=0;col1<=N-M;col1++){
            if(row1+M-1>=N||col1+M-1>=N)continue;
            bool ok=1;
            for(int row2=0;row2<M;++row2){
                for(int col2=0;col2<M;col2++){
                    if(grid1[row1+row2][col1+col2]!=grid2[row2][col2])
                        ok=0;
                }
            }
            if(ok){
                cout<<"Yes"<<endl;
                return;
            }
        }
    }
    cout<<"No"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
