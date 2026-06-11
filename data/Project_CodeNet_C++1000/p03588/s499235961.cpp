#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	int ret=INT_MAX,a,b;
	for (int i=0; i<n; i++)
		cin>>a>>b, ret=min(ret,a+b);
	cout<<ret<<"\n";
	return 0;
}