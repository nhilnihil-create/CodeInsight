#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int main(){
    int a,b,c,d,e,f;cin >> a >> b >> c >> d >> e >> f;
    vector<bool> water(31,false),sugar(3001,false);
    int ans_sum=100*a;
    int ans_sugar=0;
    for(int i=0;i<=(f/(a*100));i++){
        for(int j=0;j<=(f/(b*100));j++){
            if(100*a*i+100*b*j>f) continue;
            if(i==0&&j==0) continue;
            water[a*i+b*j]=true;
        }
    }
    for(int i=0;i*c<=30*e;i++){
        for(int j=0;i*c+j*d<=30*e;j++){
            sugar[i*c+j*d]=true;
        }
    }
    for(int i=1;i<=(f/100);i++){
        for(int j=0;j<=i*e;j++){
            if(water[i]==false||sugar[j]==false) continue;
            if(i*100+j>f) continue;
            if(((1.0*(double)j)/((double)i*100.0+(double)j))>((double)ans_sugar/(double)ans_sum*1.0)){
                ans_sum=100*i+j;
                ans_sugar=j;
            }
        }
    }
    cout << ans_sum << " " << ans_sugar << endl;
    return 0;
}