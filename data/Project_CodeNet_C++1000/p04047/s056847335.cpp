#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define all(obj) (obj).begin(),(obj).end() 
#define dump(x)  cout << #x << " = " << (x) << endl;
typedef long long lint;
using namespace std;
int main(){
	int n,ans=0;
	cin>>n;
	vector<int>l(2*n);
	rep(i,2*n)cin>>l.at(i);
	sort(all(l));
	for(int i=0;i<2*n;i+=2)ans+=l.at(i);
	cout<<ans<<endl;
}
