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

	int a, b;
	cin>>a>>b;
	if(a > 0){
		cout<<"Positive"<<endl;
	}else if(b >= 0){
		cout<<"Zero"<<endl;
	}else{
		int tmp = b - a + 1;
		if(tmp&1){
			cout<<"Negative"<<endl;
		}else{
			cout<<"Positive"<<endl;
		}
	}

	return 0;
}