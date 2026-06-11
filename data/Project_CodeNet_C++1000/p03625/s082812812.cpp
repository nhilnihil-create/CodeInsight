#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=1; i<=(int)(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define bigger (char)toupper
#define smaller (char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N;
    cin>>N;
    map<int,int,greater<int>> m;
    rep(i,N) {
        int A;
        cin>>A;
        m[A]++;
    }
    ll a=0,b=0;
    for(auto c : m) {
        if(c.se>=2) {
            a=c.fi;
            m[a]-=2;
            break;
        }
    }
    for(auto c : m) {
        if(c.se>=2) {
            b=c.fi;
            break;
        }
    }
    cout<<a*b<<endl;
}