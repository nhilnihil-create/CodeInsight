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

#define N 2010
ll n,a[100010];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    sort(a,a+n);
    if(a[0]==a[n-1]){
	if(a[0]==n-1||(1<=a[0]&&a[0]<=n/2))cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
    }
    else if(a[0]+1<a[n-1]){
	cout<<"No"<<endl;
    }
    else{
	ll b=0,c=0;
	for(int i=0;i<n;i++){
	    if(a[i]==a[0])c++;
	    else b++;
	}
	if(c+1<=a[n-1]&&a[n-1]<=c+b/2)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
    }
}


