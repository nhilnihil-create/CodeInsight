// square869120Contest #4-B
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
namespace you {
    std::string to_string(char val) {
        return std::string(1, val);
        // return std::string{val};
        // you::to_string(char)
    }
}

vector<ll> h(16);
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int n,k;
    cin>>n>>k;
    rep(i,n) cin>>h[i];
    int now=h[0];
    int see=1;
    for(int i=1;i<n;i++){
        if(now<h[i]){
            see+=1;
            now=h[i];
        }
    }
    if(k<=see) cout<<0<<endl;
    else{
        ll ans=pow(10,12);
        int num=pow(2,n-1);
        for(int i=0;i<num;i++){
            ll cur=0;
            int max_h=h[0];
            int c=1; //見える数
            for(int j=0;j<n-1;j++){
                int now_h=h[j+1];
                if((i>>j)&1){
                    if(now_h<=max_h){
                        cur+=(max_h+1-now_h);
                        now_h=max_h+1;
                    }
                    c+=1;
                }
                if(max_h<now_h) max_h=now_h;
            }
            //cout<<i<<" "<<
            if(k<=c) ans=min(ans,cur);
        }
        cout<<ans<<endl;
    }
    return 0;
}