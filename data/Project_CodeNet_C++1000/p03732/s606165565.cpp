#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1e9
#define MOD 1e9+7
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;
typedef tuple<ll, ll, ll> T;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

ll N,W,sm=0;
vector<ll> v1,v2,v3,v4;
ll w0,w,v;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>W;
    REP(i,N){
        cin>>w>>v;
        if(i==0){
            w0 = w;
            v1.push_back(v);
        }
        else{
            ll dif = w-w0;
            if(dif==0) v1.push_back(v);
            if(dif==1) v2.push_back(v);
            if(dif==2) v3.push_back(v);
            if(dif==3) v4.push_back(v);
        }
    }
    VRSORT(v1);
    VRSORT(v2);
    VRSORT(v3);
    VRSORT(v4);

    for(int i=1;i<v1.size();i++) v1[i]+=v1[i-1];
    for(int i=1;i<v2.size();i++) v2[i]+=v2[i-1];
    for(int i=1;i<v3.size();i++) v3[i]+=v3[i-1];
    for(int i=1;i<v4.size();i++) v4[i]+=v4[i-1];
    
    v1.insert(v1.begin(), 0);
    v2.insert(v2.begin(), 0);
    v3.insert(v3.begin(), 0);
    v4.insert(v4.begin(), 0);

    ll ans=0;
    REP(i,v1.size()){
        REP(j,v2.size()){
            REP(k,v3.size()){
                REP(l,v4.size()){
                    if(i*w0 + j*(w0+1) + k*(w0+2) + l*(w0+3)<=W) ans = max(ans,v1[i]+v2[j]+v3[k]+v4[l]);
                }
            }
        }
    }
    cout<<ans<<endl;
}