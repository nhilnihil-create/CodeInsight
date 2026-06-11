#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int n;
int p[100004];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		cin>>p[i];
	for(int i = 1 ; i <= n ; i ++)
		if(p[i] == i){
			swap(p[i],p[i+1]);
			ans++;
		}
	cout<<ans;
	return 0;
}