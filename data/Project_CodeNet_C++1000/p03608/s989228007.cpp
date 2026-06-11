#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,pair<int,int> > P;
typedef unsigned long long int ull;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXH=500;
const int MAXW=500;
const ll INF=1e9;

int main(){
    int N,M,R;
    cin>>N>>M>>R;
    vector<vector<int> > c(N,vector<int>(N,INF));
    vector<int> r(R);
    for(int i=0;i<R;i++){
        cin>>r[i];
        r[i]--;
    }
    sort(r.begin(),r.end());
    for(int i=0;i<M;i++){
        int a,b,cst;
        cin>>a>>b>>cst;
        a--;b--;
        c[a][b]=cst;
        c[b][a]=cst;
    }
    for(int i=0;i<N;i++) c[i][i]=0;
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
            }
        }
    }
    int ans=INF;
    do{
        int tmp=0;
        for(int i=0;i<R-1;i++){
            tmp+=c[r[i]][r[i+1]];
        }
        ans=min(ans,tmp);
    }while(next_permutation(r.begin(),r.end()));
    cout<<ans<<endl;
    return 0;
}