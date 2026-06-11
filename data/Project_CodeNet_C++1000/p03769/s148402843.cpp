#include <bits/stdc++.h>
#define ll long long
using namespace std;
int m,cnt;
vector<int>f;
vector<int>::iterator it;
int main(){
    ll n; cin>>n;
    for (m=40; n<(1ll<<m)-1; --m);
    for (int i=m; i; --i) f.push_back(i);
    for (int i=m; i; --i) f.push_back(i);
    cnt=m,n-=(1ll<<m)-1;
    for (int i=m-1; ~i; --i)
	if (n>>i&1){
	    it=f.end()-i;
	    f.insert(it,++cnt),f.insert(f.begin(),cnt);
	}
    cout<<f.size()<<endl;
    for (int i=0; i<f.size(); ++i)
	cout<<f[i]<<" ";
    return 0;
}
