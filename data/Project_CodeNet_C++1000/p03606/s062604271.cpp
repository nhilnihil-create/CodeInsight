#include<bits/stdc++.h>
#define ll long long
const int N=100005;
using namespace std;
int n,l,r,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>l>>r,ans+=r-l+1;
	cout<<ans;
    return 0;
}