#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<iomanip>
#define mod 1000000007
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mad(a,b) a=(a+b)%mod
#define mul(a,b) a=a*b%mod

#define N 510

int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a%c==0&&b%d==0){
	cout<<"No"<<endl;
    }
    else{
	cout<<"Yes"<<endl;
	ll t=(a/c)*(b/d)+10;
	ll p=t*(c*d-1)-1;
	if(t>1e9||p>1e9)cout<<1/0<<endl;
	for(int i=0;i<a;i++){
	    for(int j=0;j<b;j++){
		if(j)cout<<" ";
		if(i%c==0&&j%d==0)cout<<p;
		else cout<<-t;
	    }
	    cout<<endl;
	}
    }
}

