#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	int q;
	int a[100010],b[100010],c[100010],d[100010];
	cin >> s >> t;
	scanf("%d",&q);
	for(int i = 0 ; i < q ; i ++){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	}
	
	int cnt[2][100010] = {};
	for(int i = 0 ; i < s.size() ; i ++){
		if(s[i] == 'A')cnt[0][i+1] = cnt[0][i]+1;
		else cnt[0][i+1] = cnt[0][i]-1;
	}
	for(int i = 0 ; i < t.size() ; i ++){
		if(t[i] == 'A')cnt[1][i+1] = cnt[1][i]+1;
		else cnt[1][i+1] = cnt[1][i]-1;
	}
	for(int i = 0 ; i < q ; i ++){
		if((cnt[0][b[i]]-cnt[0][a[i]-1]+300000)%3 == (cnt[1][d[i]]-cnt[1][c[i]-1]+300000)%3)puts("YES");
		else puts("NO");
	}
}