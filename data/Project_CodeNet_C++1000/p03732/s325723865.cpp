#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef  pair<int,int> P;
typedef long long LL;

const int INF=1<<30;
const LL MOD=1000000007;

LL gcd(LL a,LL b){
    if(b==0)return a;

    return gcd(b,a%b);
}

int main(){
    LL n,w;
    cin>>n>>w;
    vector<LL> v[4];

    LL w1;
    for(LL i=0;i<n;++i){
        LL ww,v2;
        cin>>ww>>v2;
        if(i==0)w1=ww;
        v[ww-w1].push_back(v2);
         }
    for(int i=0;i<4;++i){
        sort(v[i].begin(),v[i].end());
        v[i].push_back(0);
        reverse(v[i].begin(),v[i].end());
        for(LL j=1;j<v[i].size();++j){
            v[i][j]+=v[i][j-1];
        }
    }
    LL ans=0;
    for(LL i=0;i<v[0].size();++i){
        for(LL j=0;j<v[1].size();++j){
            for(LL k=0;k<v[2].size();++k){
                for(LL l=0;l<v[3].size();++l){
                    if(w>= (i*w1+j*(w1+1)+k*(w1+2)+l*(w1+3))){
                        ans=max(ans,(v[0][i]+v[1][j]+v[2][k]+v[3][l]));
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}