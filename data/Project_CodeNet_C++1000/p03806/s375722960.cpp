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
    int n,ma,mb;
    cin>>n>>ma>>mb;
    vector<pair<pair<int,int>,int>> vec;
    rep(i,n){
        int a,b,c;
        cin>>a>>b>>c;
        vec.push_back({{a,b},c});
    }
    vector<pair<pair<int,int>,int>> vec2;
    int num=n/2;
    if (n==1){
        if (vec[0].fi.fi*mb==vec[0].fi.se*ma)cout<<vec[0].se<<endl;
        else cout<<-1<<endl;
        return 0;
    }
    for (int i=0;i<(1<<num);i++){
        bitset<20> s(i);
        int sa=0,sb=0,sc=0;
        rep(j,num){
            if (s.test(j)){
                sa+=vec[j].fi.fi;
                sb+=vec[j].fi.se;
                sc+=vec[j].se;
            }
        }
        vec2.push_back({{sa,sb},sc});
    }
    int num2=n-num;
    vvi d(201,vi(201,10000));
    for (int i=0;i<(1<<num2);i++){
        bitset<20> s(i);
        int sa=0,sb=0,sc=0;
        rep(j,num2){
            if (s.test(j)){
                sa+=vec[j+num].fi.fi;
                sb+=vec[j+num].fi.se;
                sc+=vec[j+num].se;
            }
        }
        d[sa][sb]=min(d[sa][sb],sc);
    }
    int ans=100000;
    for (auto p:vec2){
        int a=p.fi.fi,c=p.fi.se;
        int r=c%mb;
        int dd;
        if (r==0)dd=-mb;
        else dd=-r;
        while(1){
            dd+=mb;
            if (dd>200)break;
            int b=ma*(c+dd)/mb-a;
            if (b<0)continue;
            else if (a==0 && b==0 && c==0 && dd==0)continue;
            else if (b>200)break;
            else if (d[b][dd]==10000)continue;
            else ans=min(ans,d[b][dd]+p.se);
        }
    }
    if (ans==100000)cout<<-1<<endl;
    else cout<<ans<<endl;
    

    return 0;
}