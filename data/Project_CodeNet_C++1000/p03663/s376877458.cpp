#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 998244353
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int cur = 1;
	int dig = -1;
	for(int i=1;i<=9;i++){
		char res;
		cur = cur * 10;
		cout<<"? "<<cur<<endl;
		cin>>res;
		if( res == 'N'){
			dig = i;
			break;
		}
	}
	if( dig == -1){
		ll cur = 1000000000;
		while( cur > 1 ){
			cout<<"? "<<cur-1<<endl;
			char res;
			cin>>res;
			if(res == 'N' ){
				cout<<"! "<<cur<<endl;
				cout<<flush;
				return 0;
			}
			cur = cur/10;
		}
		cout<<"! "<<1<<endl;
		cout<<flush;
		return 0;
	}
	int cv = 0;
	for(int i=1;i<=dig-1;i++){
		int yes = 0, no = 10;
		if( cv == 0 )yes = 1;
		while( no-yes > 1 ){
			int mid = ( yes + no ) / 2;
			int ask = cv + mid;
			cout<<"? "<<ask<<endl;
			char res;
			cin>>res;
			if( res == 'Y' ){
				yes = mid;
			}
			else{
				no = mid;
			}
		}
		cv += yes;
		cv *= 10;
	}
	cv *= 10;
	for(int i=0;i<=9;i++){
		if( cv != 0 ){
			cout<<"? "<<cv<<endl;
			char res;
			cin>>res;
			if( res == 'Y'){
				cout<<"! "<<cv/10<<endl;
				cout<<flush;
				return 0;
			}
		}
		cv += 10;
	}
	return 0;
}