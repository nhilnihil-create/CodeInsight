#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
int cnt[26];
signed main(){
	int h,w;
	cin>>h>>w;
	int ok1 = 0, ok2 = 0;
	if( h % 2 == 1 && w % 2 == 1 ) ok1 ++;
	if( h % 2 == 1 ) ok2 += w/2;
	if( w % 2 == 1 ) ok2 += h/2;
	for(int i=0;i<h;i++){
		string st;
		cin>>st;
		for(int j=0;j<w;j++){
			cnt[ st[j] - 'a' ] ++;
		}
	}
	for(int i=0;i<=25;i++){
		if( cnt[i] % 4 == 1 ) ok1--;
		if( cnt[i] % 4 == 2 ) ok2--;
		if( cnt[i] % 4 == 3 ){ ok1--; ok2--; }
	}
	if( ok1 >= 0 && ok2 >= 0 ){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}