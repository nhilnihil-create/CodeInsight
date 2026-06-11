#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
string a,b,c;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>a>>b>>c;
	cout<<(a[sz(a)-1]==b[0]&&b[sz(b)-1]==c[0]?"YES":"NO");
	re 0;
}