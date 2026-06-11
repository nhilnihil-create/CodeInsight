#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
#define fi first
#define se second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int ans1=0,ans2=0;
    double now=0.0;
    int dp[f+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for (int k=0;k<f+1;k++){
        if (dp[k]==0)continue;
        else{
            for (int j=1;j*c+k<f+1;j++){
                dp[j*c+k]=1;
            }
            for (int j=1;j*d+k<f+1;j++){
                dp[j*d+k]=1;
            }
        }
    }
    for (int i=0;i<31;i++){
        for (int j=0;j<31;j++){
            if (i==0 && j==0)continue;
            int w=100*a*i+100*b*j;
            if (w>=f)continue;
            else{
                int sl=f-w;
                int s=-1;
                for (int k=sl;k>=0;k--){
                    if (dp[k]==1){
                        int nn=w/100;
                        if (nn*e>=k){
                            s=k;
                            break;
                        }
                    }
                }
                if (now<=double(s)/(double(s)+double(w))){
                    ans1=w+s;
                    ans2=s;
                    now=double(s)/(double(s)+double(w));
                }
            }
            
        }
    }
    cout<<ans1<<" "<<ans2<<endl;

    return 0;
}