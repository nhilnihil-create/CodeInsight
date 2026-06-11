#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
const int MOD=998244353;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    double a,b,c,d,e,f;cin >> a >> b >> c >> d >> e >> f;
    int u=a*100,v=0;
    double t=0;
    for(int i=0;i*a*100<=f;i++){
        for(int j=0;i*a*100+j*b*100<=f;j++){
            for(int k=0;k*c<=e*(i*a+j*b);k++){
                for(int l=0;k*c+l*d<=e*(i*a+j*b);l++){
                    if(i*a*100+j*b*100+k*c+l*d>f){
                        continue;
                    }
                    if(t<(double)(k*c+l*d)/(i*a*100+j*b*100)){
                        t=(double)(k*c+l*d)/(i*a*100+j*b*100);
                        u=i*a*100+j*b*100+k*c+l*d;
                        v=k*c+l*d;
                    }
                }
            }
        }
    }
    cout << u << " " << v << endl;
}