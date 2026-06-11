#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	vector<int> vec;
	int cur = -1;
	for(int i=40;i>=1;i--){
		if( n >= ( 1LL<<i ) - 1 ){	
			for(int j = 1; j <= i; j ++){
				vec.pb(j);
			}
			n -= ( 1LL<< i ) -1;
			cur = i+1;
			break;
		}
	}
	for(int i=40;i>=0;i--){
		if( n >= (1LL<<i) ){
			vec.insert( vec.begin()+i, cur );
			cur++;
			n -= 1LL<<i;
		}
	}
	for(int i=1;i<cur;i++){
		vec.pb(i);
	}
	cout<<vec.size()<<endl;
	for(int i=0;i<vec.size();i++)cout<<vec[i]<<" "; cout<<endl;
	return 0;
}