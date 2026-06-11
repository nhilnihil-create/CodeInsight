#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define puts(i) cout<<i<<endl

int main(){
	string o;
	cin>>o;
	int n=0,s=0,w=0,e=0;
	rep(i,o.size()){
		if(o[i]=='N')n++;
		else if(o[i]=='S')s++;
		else if(o[i]=='W')w++;
		else if(o[i]=='E')e++;
	}
	if(((n>0&&s>0)||(s==0&&n==0))&&((e>0&&w>0)||(e==0&&w==0)))puts("Yes");
	else puts("No");
}
