#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<int,int> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;

int n;
vector<vector<int> > v(101010);
vector<int> stage(101010,-1);

int solve(int i){
    if(stage[i]>=0) {
        //cout<<i<<stage[i]<<endl;
        return stage[i];
    }
    if(v[i].size()==0) return stage[i]=0;
    else {
        vector<int> s;
        for(int j=0;j<v[i].size();j++){
            s.pb(solve(v[i][j]));
        }
        sort(s.begin(),s.end());
        int ans=0;
        for(int j=0;j<s.size();j++){
            ans=max(ans,s[j]+(int)s.size()-j);
        }
        //cout<<i<<" "<<ans<<endl;
        return stage[i]=ans;
    }
}

int main(){
    int i,j;
    
    cin>>n;
    
    for(i=1;i<n;i++){
        int x;
        cin>>x;
        x--;
        v[x].pb(i);
    }
    cout<<solve(0)<<endl;
    

    return 0;
}