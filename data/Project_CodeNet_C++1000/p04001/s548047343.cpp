
#include <bits/stdc++.h>


using namespace std;
double pi=3.14159265358979323846264338;

string s;
int lnth;
long long ans,cur;
void dfs(long long a,int b){
	if(b==lnth-1){
		if(a!=0)ans+=cur+a*10+(long long)(s[lnth-1]-'0');
		ans+=cur+a+(long long)(s[lnth-1]-'0');
		return;
	}
	if(a!=0)dfs(a*10+(long long)(s[b]-'0'),b+1);
	cur+=a;
	dfs((long long)(s[b]-'0'),b+1);
	cur-=a;
}

int main(){
	cin>>s;
	ans=0;
	cur=0;
	lnth=s.length();
	dfs(cur,0);
	cout<<ans<<endl;
			
	return 0;
}
