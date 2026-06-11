#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
ll n,a[100010];
int main(){
    cin>>n;
    lol(i,n)cin>>a[i];
    ll s=2,ans=a[0]-1;
    for(int i=1;i<n;i++){
	if(s==a[i])s++;
	else{
	    ans+=(a[i]-1)/s;
	}
    }
    cout<<ans<<endl;
    return 0;
}
