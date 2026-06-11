#include<iostream>
#include<cstring>
using namespace std;
const int MAX=100005;
int cnt[MAX];
int main(){
	int n;
	cin >> n;
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		cnt[a]++;
	}
	int ans=0;
	ans=cnt[0]+cnt[1];
	for(int i=1;i<MAX;i++){
		if(cnt[i]+cnt[i-1]+cnt[i+1]>ans) ans=cnt[i]+cnt[i-1]+cnt[i+1];
	}
	cout << ans;
	return 0;
}