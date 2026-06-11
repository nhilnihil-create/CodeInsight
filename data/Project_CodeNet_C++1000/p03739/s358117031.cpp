#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
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
    ll a[n];
    rep(i,n)cin>>a[i];
    ll ans1 =0,ans2=0;
    ll sum =0;
    rep(i,n){
        sum+=a[i];
        if(i%2==0){
            if(sum<=0){
                ans1+=abs(sum)+1;
                sum=1;
            }
        }
        else{
            if(sum>=0){
                ans1+=sum+1;
                sum=-1;
            }
        }
    }
    sum=0;
    rep(i,n){
        sum+=a[i];
        if(i%2==1){
            if(sum<=0){
                ans2+=abs(sum)+1;
                sum=1;
            }
        }
        else{
            if(sum>=0){
                ans2+=sum+1;
                sum=-1;
            }
        }
    }
    cout<<min(ans1,ans2)<<endl;
}
