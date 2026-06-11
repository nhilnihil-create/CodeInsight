#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fir first
#define sec second
#define MOD 1000000007
#define vvi vector<vector<int> >
#define vvs vector<vector<string> >
#define ss string
#define pa pair<int, int>
#define pp pair<int, pa>
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vvl vector<vl>
#define loopin(i, n) for(int i = 0; i < (n); i++)
#define loopa(i, a, n) for(int i = a; i <= (n); i++)
#define loopdec(i, n) for(int i = n-1; i >= 0; i--)
const int mod=1e9+7;


void solve(){
	int n,l;
	cin>>n>>l;
	vs s;
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		s.pb(temp);
	}
	sort(s.begin(),s.end());
	string ans="";
	int i=0;
	while(i<s.size()){
		ans=ans+s[i];
		i++;
	}
	cout<<ans<<endl;


}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0); cout.tie(0);
cin>>ws;

        solve();


return 0;
}
