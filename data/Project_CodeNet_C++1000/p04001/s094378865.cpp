#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
long long ans=0;
long long sti(int l,int r){
	long long sum=0;
	for(int i=l;i<=r;i++){
		sum=sum*10+s[i]-'0';
	}
	return sum;
}
void dfs(){
	if(v.size()+1==s.size()){
		long long l=0,sum=0;
		for(int i=0;i<s.size()-1;i++){
			if(v[i]==1){
				sum+=sti(l,i);
				l=i+1;
			}
		}
		sum+=sti(l,s.size()-1);
		//cout<<sum<<endl;
		ans+=sum;
	}else{
		v.push_back(0);
		dfs();
		v.pop_back();
		v.push_back(1);
		dfs();
		v.pop_back();
	}
}
int main(){
	cin>>s;
	dfs();
	cout<<ans<<endl;
}
