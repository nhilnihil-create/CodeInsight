#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
signed main(){
	string s;
	int n,k;
	cin>>s>>k;
	n = s.size();
	for(int i=0;i<n;i++){
		int cgs = 'z'+1-s[i];
		if( s[i] == 'a' ) cgs = 0;
		if( k >= cgs ){
			s[i] = 'a';
			k -= cgs;
		}
	}
	if( k > 0 ){
		int rem = k % 26;
		for(int i=0;i<rem;i++){
			s[n-1]++;
			if( s[n-1] == 'z'+1 ) s[n-1] = 'a';
		}
	}cout<<s<<endl;
	return 0;
}