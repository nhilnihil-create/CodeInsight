#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
	string s,t;
	cin>>s;
	t=s;
	reverse(t.begin(),t.end());
	map<char,char> m;
	m['p']='q';
	m['q']='p';
	m['b']='d';
	m['d']='b';
	int siz=t.size();
	lol(i,siz){
		t[i]=m[t[i]];
	}
	cout<<(s==t?"Yes":"No")<<endl;
	return 0;
}
