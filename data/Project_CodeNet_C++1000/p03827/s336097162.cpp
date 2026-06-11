#include<bits/stdc++.h>
#define turbo(){	\
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
}
using namespace std;
typedef long long ll;
int main()
{
	turbo();
	int i,n,x=0,mx=0;
	string s;
	cin>>n;
	cin>>s;
	for(i=0;i<n;i++){
		if(s[i]=='I'){
			x++;
		}
		else{
			x--;
		}
		mx=max(x,mx);
	}
	cout<<mx<<endl;
	return 0;	
}
