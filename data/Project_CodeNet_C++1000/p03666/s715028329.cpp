#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
bool ch(ll a, ll b, ll x, ll y){
	if(a>b){
		swap(a,b);
	}
	if(x>y){
		swap(x,y);
	}
	bool z=0;
	if(x<=a&&a<=y || x<=b&&b<=y){
		z=1;
	}
	return z;
}
int main(){
	IOS
	ll n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	for(int i=1;i<=n;i++){
		/*
		a+((i-1)*c),a+((i-1)*d);
		a-((i-1)*d),a-((i-1)*c);
		b-((n-i)*d),b-((n-i)*c);
		b+((n-i)*c),b+((n-i)*d);
		*/
		if( ch(a+((i-1)*c),a+((i-1)*d),
				b+((n-i)*c),b+((n-i)*d))==1||
			ch(a+((i-1)*c),a+((i-1)*d),
				b-((n-i)*d),b-((n-i)*c))==1||
			ch(a-((i-1)*d),a-((i-1)*c),
				b+((n-i)*c),b+((n-i)*d))==1||
			ch(a-((i-1)*d),a-((i-1)*c),
				b-((n-i)*d),b-((n-i)*c))==1){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}
/*
 
*/