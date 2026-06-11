#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define ll long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.pb(x);
	}
	sort(a.begin(),a.end(),greater<ll>());
	a.pb(0);
	for(int i=0;i<n;i++){
		if( i+1 >= a[i+1] ){
			//cout<<i+1<<" "<<a[i+1]<<" "<<a[i+2]<<endl;
			int len1 = a[i] - i;
			int len2 = 0;
			int last = -1;;
			for(int j=i+1;j<=n;j++){
				if( i < a[j]){ len2++; last=j;}
				if( i==a[j] ){ len2++; last=j; j=n+1;}
			}
			if(last != -1)len2+=a[last]-i;
			//cout<<i<<" "<<len1<<" "<<len2<<endl;
			if( len1%2==0 || (len2!=0 && len2%2==0)){
				cout<<"First"<<endl;
				return 0;
			}
			else {
				cout<<"Second"<<endl;
				return 0;
			}
		}
	}
	return 0;
}