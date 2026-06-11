#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll res=1;
    int tmp=-1;//0なら単調非減少1なら単調非増加-1なら未決定
    rep(i,n-1){
        //cout<<i<<" "<<tmp<<endl;
        if(tmp==1){
            if(a[i]>=a[i+1])continue;
            else{
                tmp=-1;
                res++;
                continue;
            }
        }else if(tmp==0){
            //if(i==1)cout<<a[i]<<" "<<a[i+1]<<endl;
            if(a[i]<=a[i+1])continue;
            else{
                tmp=-1;
                res++;
                continue;
            }
        }else{
            if(a[i]==a[i+1])continue;
            else if(a[i]>a[i+1]){
                tmp=1;
                continue;
            }else{
                tmp=0;
                continue;
            }
        }
    }
    cout<<res<<endl;
}