#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	
	bool flg=false;

	for(int m=0;m<n;m++){
	if(m*c-(n-1-m)*d<=b-a && b-a<=d*m-(n-1-m)*c)flg=true;
    } 

cout<<(flg?"YES":"NO")<<endl;  

}
//  c  d
// -d  -c
// b-a