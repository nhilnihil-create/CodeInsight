#include<bits/stdc++.h>
using namespace std;

int sum=0;
typedef long long int LLI;

vector<LLI>ar;

void debug(vector<LLI>&v)
{
	cout<<v.size()<<" :";
	for(auto e:v) cout<<e<<" ";
	cout<<"  ";
	return;
}

int f(string& s,vector<LLI>&v)
{
	sort(v.begin(),v.end(),greater<int>());
	//debug(v);
	if(!v.size()){
		LLI num=0,p=1;
		LLI lo=0,hi=s.size()-1;
		for(LLI i=hi;i>=lo;--i) num+=(s[i]-'0')*p,p*=10;
		//cout<<"sum: "<<num<<"\n";
		ar.emplace_back(num);
		return num; 
	}
	if(v.size()==1){
		LLI num=0,val=0;
		LLI lo,hi=s.size()-1;
		lo=ceil(v[0]/2.0);
		LLI p=1;
		for(LLI i=hi;i>=lo;--i) num+=(s[i]-'0')*p,p*=10;
		val+=num;
		hi=lo-1,lo=0;
		p=1;
		num=0;
		for(LLI i=hi;i>=lo;--i) num+=(s[i]-'0')*p,p*=10;
		val+=num;
		//cout<<"sum: "<<val<<"\n";
		ar.emplace_back(val);
		return val;
	}
	//reverse(v.begin(),v.end());
	LLI hi=s.size()-1,lo;
	LLI val=0;
	for(LLI i=0;i<v.size();++i){
		LLI num=0;
		//if(i==v.size()-1) lo=0;
		lo=ceil(v[i]/2.0);
		LLI p=1; 
		for(LLI j=hi;j>=lo;--j) num+=(s[j]-'0')*p,p*=10;
		hi=lo-1;
		//cout<<num<<" ";
		val+=num; 
	}
	hi=lo-1,lo=0;
	LLI num=0,p=1;
	for(LLI j=hi;j>=lo;--j) num+=(s[j]-'0')*p,p*=10;
	val+=num;
	ar.emplace_back(val);
	//cout<<"\nsum: "<<val<<"\n";
	return val;
}

int find_sum(string& s,LLI cur,LLI hi,vector<LLI>&v)
{
	if(cur>hi) return f(s,v);
	sum+=find_sum(s,cur+2,hi,v);
	vector<LLI>q;
	for(auto e:v) q.emplace_back(e);
	q.emplace_back(cur);
	sum+=find_sum(s,cur+2,hi,q);
	return sum;
}

void solve()
{
	string s;
	cin>>s;
	LLI l=s.size();
	vector<LLI>v;
	if(l==1) cout<<s;
	else{
		LLI useless=find_sum(s,1,2*l-3,v);
		LLI ans=0;
		for(auto e:ar) ans+=e;
		cout<<ans;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}