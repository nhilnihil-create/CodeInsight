#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

bool ans(){
    char a;
    cin>>a;
    return a=='Y';
}

void solve(int l){
    ll a = 1;
    rep(i,0,l-1) a*=10;
    ll b = a*10;
    while(a+1 != b){
        ll m = (a+b)/2;
        cout<<"? "<<m<<"0"<<endl;
        if(ans()) b = m;
        else a = m;
    }
    cout<<"! "<<b<<endl;
    exit(0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    rep(l,1,11){
        cout<<"? ";
        cout<<1;
        rep(i,0,l-1) cout<<0;
        cout<<endl;
        if(!ans()) solve(l-1);
    }
    // of the form 1000...;
    for(int l = 9; l>0; --l){
        cout<<"? ";
        rep(i,0,l) cout<<9;
        cout<<endl;
        if(!ans()){
            cout<<"! 1";
            rep(i,0,l) cout<<0;
            cout<<endl;
            return 0;
        }
    }
    cout<<"! 1"<<endl;
    return 0;
}
