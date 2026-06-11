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
    int N;
    cin>>N;
    vi a(N);
    rep(i,N) cin>>a[i];
    int zero=0,one=0,two=0;
    rep(i,N) {
        if(a[i]%4==0) two++;
        else if(a[i]%2==0) one++;
        else zero++;
    }
    if(one==0) {
        if(zero<=two+1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else {
        if(zero<=two) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}