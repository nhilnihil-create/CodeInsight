#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n,W;
    cin>>n>>W;
    int w[n],v[n];
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    vector<int> vec[4];
    for(int i=0;i<n;i++){
        vec[w[i]-w[0]].push_back(v[i]);
    }
    for(int i=0;i<4;i++){
        vec[i].push_back(INF);
        sort(vec[i].begin(),vec[i].end(),greater<int>());
        vec[i][0]=0;
        for(int j=1;j<vec[i].size();j++){
            vec[i][j]=vec[i][j]+vec[i][j-1];
        }
    }
    int ans=0;
    for(int i=0;i<vec[0].size();i++){
        for(int j=0;j<vec[1].size();j++){
            for(int k=0;k<vec[2].size();k++){
                for(int l=0;l<vec[3].size();l++){
                    if(((ll)(i+j+k+l)*w[0]+j+2*k+3*l)<=W){
                        ans=max(ans,vec[0][i]+vec[1][j]+vec[2][k]+vec[3][l]);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
