#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;

bool check(int x,int y,int n){
    rep(i,n/x+1){
        rep(j,n/y+1){
            if(i*x+j*y==n) return true;
        }
    }
    return false;
}

int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    double per=0;
    pair<int,int> ans;
    ans.first=a*100;
    repi(i,1,f/100){
        if(check(a,b,i)){
            for(int j=e*i;j>=0;j--){
                if(check(c,d,j)){
                    if(100*i+j<=f){
                        if(per<(double)j/(double)i){
                            per=(double)j/(double)i;
                            ans.first=i*100+j;
                            ans.second=j;
                        }
                    break;
                    }
                }
            }
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
}