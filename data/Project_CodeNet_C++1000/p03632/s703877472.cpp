#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b,c,d; cin>>a>>b>>c>>d;
	vector<int> v(101);
	for(int i=a; i<b; i++) v[i]=1;
	vector<int> w(101);
	for(int i=c; i<d; i++) w[i]=1;
	int cnt=0;
	rep(i,101){
		if(v[i]+w[i]==2) cnt++;
	}
	cout<<cnt<<endl;
}