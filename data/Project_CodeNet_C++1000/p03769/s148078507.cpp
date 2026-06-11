#include<bits/stdc++.h>
using namespace std;

#define REP(i,x,y) for(ll i=x; i<=y; i++)
#define BIT(t) (1ll << (t))
#define PER(i,y,x) for(ll i=y; i>=x; i--)
#define SIZE(v) ll(v.size())
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
typedef long long ll;

ll const MAX = 100;

int main(){
    ll n;
    cin >> n;
    ll mx = MAX;
    ll t = 0;
    while(BIT(t+1) - 1 <= n){
        t++;
    }
    vll seq;
    REP(i,1,mx){   
        seq.push_back(i);
    }
    ll rem = n - (BIT(t)-1);
    REP(i,0,t-1){
        if(BIT(i)&rem){
            seq.push_back(mx);
            mx--;
            rem-=BIT(i);
        }
        seq.push_back(i+1);
    }
    cout << seq.size() << endl;
    REP(i,0,seq.size()-1){
        cout << seq[i];
        if(i < seq.size()-1){
            cout << " ";
        }
    }
    cout << endl;
}