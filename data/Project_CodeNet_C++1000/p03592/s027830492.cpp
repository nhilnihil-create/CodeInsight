#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define until(x) while(!(x))
#define unless(x) if(!(x))
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define pc __builtin_popcount

int32_t main(){
	int r,c,k;
	cin>>r>>c>>k;
	for(int i=0;i<=r;i++){
		for(int j=0;j<=c;j++){
			//cout<<i<<" "<<j<<" "<<i*c+j*r-2*i*j<<"\n";
			if((i*c + j*r - 2*i*j)==k){
				cout<<"Yes\n";
				return 0;
			}
		}
	}
	cout<<"No\n";
}
