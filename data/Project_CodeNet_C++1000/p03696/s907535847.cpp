#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define bg begin()
#define end end()
#define sz size()
#define vi vector<int>
#define vl vector<long long int>
int main(){
	fast;
ll n;
	cin>>n;
	string s;
	cin>>s;
	ll cnt=0;
	string t="";
	for(ll i=0;i<n;i++)
	{
		if(s[i]==')' && cnt==0)
			t='('+t;
		else if(s[i]==')') 
			cnt--;
		else	
			cnt++;
		t+=s[i];
	}
	while(cnt>0)
	{
		t+=')';
		cnt--;
	}
	cout<<t;
	return 0;
}

