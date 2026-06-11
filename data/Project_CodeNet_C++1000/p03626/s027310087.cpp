#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;

const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
int main(){
    int n;cin>>n;
    vector<string> s(2);
    rep(i,2)cin>>s[i];
    ll ans =1;
    bool last = true;
    rep(i,n){
        if(s[0][i]==s[1][i]){
            if(!(last)||i==0){
                ans*=1;
            }
            else{
                ans*=2;
            }
            last = true;
        }
        else{
            if(i==0){
                ans*=2;
                last=false;
                i++;
                continue;
            }
            if(!last){
                ans*=3;
            }
            else{
                ans*=2;
            }
            i++;
            last =false;
        }
        ans%=mod;
    }
    cout<<ans*3%mod<<endl;
}