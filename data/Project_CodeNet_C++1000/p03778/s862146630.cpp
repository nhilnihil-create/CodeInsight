#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int w,a,b; cin>>w>>a>>b;
	int aw=a+w, bw=b+w;
	if(b<=aw&&bw>=a) cout<<0<<endl;
	else if(bw<a) cout<<a-bw<<endl;
	else if(aw<b) cout<<b-aw<<endl;
}