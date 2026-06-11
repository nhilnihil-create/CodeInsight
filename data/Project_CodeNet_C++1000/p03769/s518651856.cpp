#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;

long long n;
int c,i;
vector<int> v1,v2;
int main(){
	cin>>n;n++;
	while(n>1){
		if(n&1){
			v2.push_back(++c);
		}
		v1.push_back(++c);
		n/=2;
	}
	cout<<c*2<<endl;
	rep(i,c) cout<<i<<' ';
	for(i=0;i<v1.size();i++) cout<<v1[i]<<' ';
	while(!v2.empty()) {cout<<v2.back()<<' ';v2.pop_back();}
	return 0;
}