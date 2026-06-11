#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
ll n,a,b;
vector<ll> h;
bool die(ll x){
    ll count=0;
    REP(i,n){
        ll life = h[i] - x*b;
        if(life>0){
            count+=(life+a-b-1)/(a-b);
        }
    }
    if(count<=x){
        return true;
    }else{
        return false;
    }
}
ll bin_search(ll start, ll end){
    if(start+1==end) return end;
    if(die((start+end)/2)){
        return bin_search(start,(start+end)/2);
    }else{
        return bin_search((start+end)/2,end);
    }
}

int main(){
     cin >> n >> a >> b;
    REP(i,n){
        ll hh;
        cin >> hh; h.push_back(hh);
    }
    sort(h.begin(), h.end(), greater<ll>());
    ll ans = bin_search(0,1000000000);
    cout << ans << endl;

}