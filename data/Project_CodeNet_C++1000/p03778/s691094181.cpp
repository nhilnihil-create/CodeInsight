#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int mod=1e9+7;

void solve(){
	int w,a,b,d=0;
	cin>>w>>a>>b;
	if(b+w<=a){
		d=a-b-w;
	}
	else if(b>=a+w){
		d=b-a-w;
	}
	cout<<d;

}

int main(){
int test=1;
// cin>>test;
while(test--){
	solve();
	cout<<endl;
}

return 0;
}
