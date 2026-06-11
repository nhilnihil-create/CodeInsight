#include<bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
 
typedef long long ll;
typedef pair<int,int> P;
 
int main(){
	int n;
	cin>>n;
	map<int,int>mp;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	bool ok=true;
	if(n%2==1&&mp[0]!=1)ok=false;
	int start=1;
	if(n%2==1)start=2;
	for(int i=start;i<n;i+=2)if(mp[i]!=2)ok=false;
	if(!ok)cout<<0<<endl;
	else{
		ll res=1;
		for(int i=0;i<n/2;i++){
			res*=2;
			res%=MOD;
		}
		cout<<res<<endl;
	}
	return 0;
}
