#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define all(obj) (obj).begin(),(obj).end() 
#define dump(x)  cout << #x << " = " << (x) << endl;
typedef long long lint;
using namespace std;
int main(){
	lint x,t;
	cin>>x>>t;
	cout<<(x-t<0?0:x-t)<<endl;
}
