#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	n++;
	vector<int> v(n);
	for(int i=1; i<n; i++) cin>>v[i];
	int cnt=0;
	int pos=1;
	while(cnt<n){
		cnt++;
		if(v[pos]==2) break;
		else pos=v[pos];
	}
	cout<<(cnt<n?cnt:-1)<<endl;
}