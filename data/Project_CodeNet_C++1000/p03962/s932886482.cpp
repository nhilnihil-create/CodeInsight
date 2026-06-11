#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int a,b,c;
	cin>>a>>b>>c;
	
	if(a == b && b == c)
		cout<<1;
	else if(a != b && a != c && b != c)
		cout<<3<<endl;
	else{
			cout<<2<<endl;
	}
}
