#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

	int n;
	cin>>n;
	ll a1 = 1;
	ll b1 = 1;
	ll mul;
	while(n--){
			int a,b;
			cin>>a>>b;
			ll x = a1 / a;
			if(a1 % a != 0)
				x++;
			
			ll y = b1 / b;
			if(b1 % b != 0)
				y++;
			mul = max(x,y);
			a1 = a * mul;
			b1 = b * mul;
	}
	
	cout<<a1+b1<<endl;
	
}
  
