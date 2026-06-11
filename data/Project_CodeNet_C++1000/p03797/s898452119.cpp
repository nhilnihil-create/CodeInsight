#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rrep(i,n) for(int i=1; i<=(int)(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define bigger (char)toupper
#define smaller(char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ll S,c;
    cin>>S>>c;
    ll ans=0;
    if(S*2<=c) {
        ans+=S;
        S=0;
        c-=ans*2;
        ans+=c/4;
        cout<<ans<<endl;
    }
    else {
        ll h=c/2;
        c-=h*2;
        S-=h;
        ans+=h;
        cout<<ans<<endl;
    }
}