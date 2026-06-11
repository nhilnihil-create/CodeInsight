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
    string S;
    cin>>S;
    int N=S.size();
    int n=0,e=0,w=0,s=0;
    rep(i,N) {
        if(S[i]=='N') n++;
        else if(S[i]=='E') e++;
        else if(S[i]=='W') w++;
        else if(S[i]=='S') s++;
    }
    bool ok=true;
    if(n>0&&s==0) ok=false;
    else if(n==0&&s>0) ok=false;
    else if(w==0&&e>0) ok=false;
    else if(w>0&&e==0) ok=false;
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}