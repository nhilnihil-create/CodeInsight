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
	cout<<sum[s.size()-1]/2;
	
    return 0;
}
/*


ggppgggpgg

ggppgpgpgp

*/