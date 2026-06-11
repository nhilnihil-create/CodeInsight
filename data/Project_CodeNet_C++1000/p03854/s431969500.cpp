#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	string s;
	cin>>s;
	int rem=s.length();
	for(int i=s.length()-1;i>=3;i--)
	{
		// cout<<rem<<i<<endl;
		
		if(s.substr(max(i-4,0),5)=="dream")
			i-=4,rem-=5;
		else if(s.substr(max(i-6,0),7)=="dreamer")
			i-=6,rem-=7;
		else if(s.substr(max(i-4,0),5)=="erase")
			i-=4,rem-=5;
		else if(s.substr(max(i-5,0),6)=="eraser")
			i-=5,rem-=6;
		
		// cout<<rem<<i<<endl;
	}
	if(rem==0)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}

