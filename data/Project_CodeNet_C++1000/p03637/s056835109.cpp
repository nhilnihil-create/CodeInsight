#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	int cnt2 = 0, cnt4 = 0;
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		if(x%4 == 0)cnt4++;
		else if(x%2 == 0)cnt2++;
	}
	int cnt1 = n - cnt2 - cnt4;
	if(cnt1 <= cnt4){
		cout<<"Yes"<<endl;
	}else if(cnt1 == cnt4 + 1 && cnt2 == 0){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}


	return 0;
}