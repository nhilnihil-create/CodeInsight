#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
ll a,b;
int main(){
	cin>>a>>b;
	if(a>0 && b>0) cout<<"Positive\n";
	else if(a==0 || b==0) cout<<"Zero\n";
	else{
		if(b<0){
			cout<<((b-a)&1?"Positive\n":"Negative\n");
		}else if(a<0){
			cout<<"Zero\n";
		}
	}
}