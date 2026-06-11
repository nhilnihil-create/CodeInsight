#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
const ll mod = 1000000007;
void solve(){
    string s,t;int a,b,c,d;
    cin>>s>>t;
    int q;cin>>q;
    int prefs[100010]={0};
    int preft[100010]={0};
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='A') prefs[i]=1;
        else prefs[i]=2;
    }
    for(int i=0;i<t.length();i++)
    {
        if(t[i]=='A') preft[i]=1;
        else preft[i]=2;
    }
    for(int i=1;i<100010;i++)
    prefs[i]+=prefs[i-1];
    for(int i=1;i<100010;i++)
    preft[i]+=preft[i-1];
    for(int i=0;i<q;i++)
    {
        cin>>a>>b>>c>>d;
        if((prefs[b-1]-prefs[a-2])%3==(preft[d-1]-preft[c-2])%3)
        cout<<"YES\n";
        else
        cout<<"NO\n";
        
    }
}
int  main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
    //cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}