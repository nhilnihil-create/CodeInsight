#include<bits/stdc++.h>

using namespace std;
const unsigned long long MAXN=1e12+5;

long long n;
vector<int> ans,aans;
int mx;

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=59;i>=0;i--){
		if(n>=(1LL<<i)){
			n-=(1LL<<i);
			ans.push_back(i);
		}
	}
	//for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
	int crt=1;
	for(;crt<=ans[0];crt++){
		if(crt!=1) aans.insert(aans.begin()+crt-1,crt);
		else aans.push_back(crt);
		aans.push_back(crt);
	}
		aans.push_back(crt);
		aans.push_back(crt++);
	for(int i=1;i<ans.size();i++){
		for(vector<int>::iterator it=aans.begin();it!=aans.end();it++){
			if(*it==ans[i]+1){
				aans.insert(it,crt);
				break;
			}
		}
		aans.push_back(crt++);
	}
	cout<<aans.size()<<endl;
	for(int i=0;i<aans.size();i++) cout<<aans[i]<<' ';
}