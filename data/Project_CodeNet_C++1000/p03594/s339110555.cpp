#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
int field[1000][1000];
signed main(){
	int h,w,d;
	cin>>h>>w>>d;
	string st = "RYGB";
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			int wa = i+j;
			int sa = i-j+w;
			if( ( wa % (2*d) ) >= d ) field[i][j] ++;
			if( ( sa % (2 * d)) >= d ) field[i][j] += 2;
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout<<st[field[i][j]];
		}
		cout<<endl;
	}
	return 0;
}