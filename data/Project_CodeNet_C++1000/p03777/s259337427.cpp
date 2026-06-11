#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int mod=1e9+7;

void solve(){
	char a,b;
	cin>>a>>b;
	if(a=='H'){
		cout<<b;
	}
	else{
		cout<<((b=='H')?'D':'H');
	}
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
