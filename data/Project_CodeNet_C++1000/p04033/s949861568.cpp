#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll a,b;
	cin>>a>>b;
	if(a<0&&b>=0){
		cout<<"Zero"<<endl;
	}else if(a==0&&b==0){
		cout<<"Zero"<<endl;
	}else if(a<0&&b<0){
		if((b-a)%2==0){
			cout<<"Negative"<<endl;
		}else{
			cout<<"Positive"<<endl;
		}
	}else if(a>0&&b>0){
		cout<<"Positive"<<endl;
	}
}
