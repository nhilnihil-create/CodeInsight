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
    vi L(2*N);
    rep(i,2*N) cin>>L[i];
    sort(all(L));
    int counter=0;
    for(int i=0; i<2*N; i+=2) counter+=L[i];
    cout<<counter<<endl;
}