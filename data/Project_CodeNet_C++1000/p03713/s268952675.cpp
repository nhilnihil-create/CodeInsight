#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define pb push_back
#define mp make_pair
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    int H,W;cin>>H>>W;
    int ans=min(H,W);
    vector<int>vec(3);
    if(H%3!=0&&W%3!=0){
        for(int i=1;i<=H/2;i++){
            vec[0]=i*W;
            if(W%2==0)vec[1]=vec[2]=(H-i)*W/2;
            else{
                vec[1]=(H-i)*(W/2);
                vec[2]=(H-i)*(W/2+1);
            }
            sort(vec.rbegin(),vec.rend());
            ans=min(ans,vec[0]-vec[2]);
        }
        for(int i=1;i<=W/2;i++){
            vec[0]=H*i;
            if(H%2==0)vec[1]=vec[2]=(W-i)*H/2;
            else{
                vec[1]=(W-i)*(H/2);
                vec[2]=(W-i)*(H/2+1);
            }
            sort(vec.rbegin(),vec.rend());
            ans=min(ans,vec[0]-vec[2]);
        }
    }
  	else ans=0;
    cout<<ans<<endl;
}