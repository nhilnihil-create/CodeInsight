#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	map<int, int> cnt;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		cnt[a]++;
	}
	int m=n;
	for(int i=n-1; i>0; i--){
		if(cnt[i]!=0){
			m=i;
			break;
		}
	}

	bool flg=true;
	for(int i=m; i>m/2+1; i--){
		flg&=(cnt[i]>=2);
	}
	for(int i=1; i<m/2; i++){
		flg&=(cnt[i]==0);
	}
	if(m%2==0){
		flg&=(cnt[m/2]==1)&(cnt[m/2+1]>=2);
	}else{
		flg&=(cnt[m/2]==0)&(cnt[m/2+1]==2);
	}

	if(flg) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}