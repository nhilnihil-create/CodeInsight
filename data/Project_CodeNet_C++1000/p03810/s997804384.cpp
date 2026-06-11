#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
vector<int> a;
int n;
int gcd(int x,int y){
	while( x*y > 0){
		if( x>y ) x= x%y;
		else y = y%x;
	}
	return x+y;
}
int hantei(int turn){
	int even_cnt=0, one_cnt=0;
	for(int i=0;i<n;i++){
		if( a[i] % 2 == 0 )even_cnt++;
		if( a[i] == 1 ) one_cnt++;
	}
	if( even_cnt % 2 == 1 )return turn;
	if( even_cnt < n-1 )return -turn;
	if( one_cnt > 0)return -turn;
	for(int i=0;i<n;i++){
		if( a[i]%2 ) a[i]--;
	}
	int gc = a[0];
	for(int i=1;i<n;i++){
		gc = gcd(gc,a[i]);
	}
	for(int i=0;i<n;i++){
		a[i] /= gc;
	}
	return hantei(-turn);
}
signed main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.pb(x);
	}
	int ans = hantei(1);
	if( ans == 1 )cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	return 0;
}