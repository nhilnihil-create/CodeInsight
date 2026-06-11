#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	int total,o_sea;
	total =o_sea=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='b'&&o_sea<b&&total<a+b){
			cout<<"Yes"<<"\n";
			o_sea++;
			total ++;
		}else if(s[i]=='a'&&total<a+b){
			cout<<"Yes"<<"\n";
			total++;
		}else{
			cout<<"No"<<"\n";
		}
		
	}
}
