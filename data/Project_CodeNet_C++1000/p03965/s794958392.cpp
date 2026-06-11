#include<bits/stdc++.h>
 
using namespace std;
#define int long long
#define N 666666
int sum[N];
signed  main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='g') sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1]-1;
	}
	//cout<<sum[s.size()-1]<<'\n';
	if(sum[s.size()-1]>0) cout<<sum[s.size()-1]/2;
	else cout<<sum[s.size()-1];
    return 0;
}
/*


ggppgggpgg

ggppgpgpgp

*/