//E.H//
# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int n,m;
bool memo[100005];
int byk[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    memo[1]=1;
    for(int i=1;i<=n;i++){
        byk[i]=1;
    }
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        if(memo[a]==1){
            memo[b]=true;

        }
        byk[a]--;
        byk[b]++;
        if(byk[a]==0) memo[a]=false;
        //cout<<i<<" "<<byk[a]<<" "<<byk[b]<<endl;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(memo[i] && byk[i]>0){
            //cout<<i<<endl;
            ans++;
        }
    }
    cout<<ans<<endl;
}