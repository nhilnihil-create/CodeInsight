#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define N 100010
ll n,x[N];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>x[i];
    ll m=0,k=0,ans=1;
    for(int i=0;i<n;i++){
	for(;k<n;k++){
	    if(m*2+1<=x[k])m++;
	    else break;
	}
	ans=ans*(m+(k<n))%mod;
	m--;
    }
    cout<<ans<<endl;
    return 0;
}
