#include <bits/stdc++.h>
using namespace std;
const int N=2000;
typedef long long ll;
typedef pair<ll,ll>lpa;
vector<ll>ve[5];
int main() {

    ll n,W,w1,w,v;
    cin>>n>>W;
    cin>>w1>>v;
    for(int i=0;i<=3;i++) ve[i].push_back(0);
    ve[w1-w1].push_back(v);
    for(int i=1;i<n;i++){
        cin>>w>>v;
        ve[w-w1].push_back(v);
    }
   // cout<<"3"<<endl;

    for(int i=0;i<=3;i++){
        sort(ve[i].begin()+1,ve[i].end(),greater<ll>());
    }

    //cout<<"3"<<endl;
    for(int i=0;i<=3;i++){
        for(int j=2;j<ve[i].size();j++){
             ve[i][j]=ve[i][j-1]+ve[i][j];
        }
    }
    ll ans=0;
    for(int i=0;i<ve[0].size();i++){
        for(int j=0;j<ve[1].size();j++){
            for(int r=0;r<ve[2].size();r++){
                for(int k=0;k<ve[3].size();k++){
                    if(i*w1+j*(w1+1)+r*(w1+2)+k*(w1+3)<=W)
                     ans=max(ans,ve[0][i]+ve[1][j]+ve[2][r]+ve[3][k]);

                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


