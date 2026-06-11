#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define all(x) (x).begin(),(x).end()

int main(){
	vector<ll> v(3);
	rep(i,3) cin>>v[i];
	sort(all(v));
	ll red, blue;
	if(v[2]%2==0){
		red=v[2]/2; blue=v[2]/2;
	} else {
		red=v[2]/2; blue=v[2]-v[2]/2;
	}
	red*=v[0]*v[1]; blue*=v[0]*v[1];
	cout<<abs(red-blue)<<endl;
}