#include<bits/stdc++.h>
using namespace std;
string s[2];
int n;
const long long MOD=1000000007;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>s[0]>>s[1];
	int back=0;
	long long res=1;
	for(int i=0;i<n;i++){
		if(s[0][i]==s[1][i]){
			if(back==0)
				res*=3LL;
			if(back==1)
				res*=2LL;
			if(back==2)
				res*=1LL;
			back=1;
		}
		else{
			if(back==0)
				res*=6LL;
			if(back==1)
				res*=2LL;
			if(back==2)
				res*=3LL;
			back=2;
			i++;
		}
		res%=MOD;
	}
	cout<<res<<endl;
	return 0;
}
