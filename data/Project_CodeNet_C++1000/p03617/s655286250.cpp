#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)
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
    ll Q,H,S,D,N;
    cin>>Q>>H>>S>>D>>N;
    ll a=N/2,b=N%2;
    cout<<a*min({Q*8,H*4,S*2,D}) + b*min({Q*4,H*2,S})<<endl;
}