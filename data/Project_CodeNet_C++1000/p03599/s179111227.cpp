//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
ll a,b,c,d,f;
ll e;
bool w[3005],s[3005];
ll answ,anss;
long double p=-1;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>a>>b>>c>>d>>e>>f;
    for(int i=0;100*a*i<=f;i++){
        for(int j=0;100*b*j<=f;j++){
            if(100*a*i+100*b*j<=f){
                w[100*a*i+100*b*j]=true;
            }
        }
    }
    for(int i=0;c*i<=f;i++){
        for(int j=0;d*j<=f;j++){
            if(c*i+d*j<=f){
                s[c*i+d*j]=true;
            }
        }
    }
    for(int i=1;i<=f;i++){
        for(int j=0;j<=f;j++){
            if(w[i]&&s[j]){
                long double W=i,S=j;
                if(i+j<=f&&100*S<=e*W&&p*(S+W)<100.0*S){
                    p=100.0*(S/(S+W));
                    answ=i;
                    anss=j;
                }
            }
        }
    }
    cout<<answ+anss<<" "<<anss<<endl;
    
}
