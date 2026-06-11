#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int mod = 1e9+7;
const int mx = INT_MAX;
const long double pi = 4*atan((long double)1);
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define file "orz"
const int mxN=1e5+5;
int pref[mxN], pref2[mxN];
int main()
{
    //freopen(file".inp","r",stdin);
    //freopen(file".out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s,t;
    cin>>s>>t;
    for(int i=0;i<s.length();i++)
    {
    	if(s[i]=='A')
    		pref[i+1]=pref[i]+1;
    	else
    		pref[i+1]=pref[i]-1;
	}
	for(int i=0;i<t.length();i++)
    {
    	if(t[i]=='A')
    		pref2[i+1]=pref2[i]+1;
    	else
    		pref2[i+1]=pref2[i]-1;
	}
	int q;
	cin>>q;
	for(int i=0,a,b,c,d;i<q;i++)
	{
		cin>>a>>b>>c>>d;
		int x=pref[b]-pref[a-1];
		int y=pref2[d]-pref2[c-1];
//		cout<<x<<" "<<y<<endl;
		x=(x+mxN)%3;
		y=(y+mxN)%3;
//		cout<<x<<" "<<y<<endl;
		if(x==y)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
