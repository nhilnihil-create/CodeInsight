#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
	string s; cin>>s;
	char a=s[0],b=s[s.size()-1];
	int ans=s.size()-2;
	if(a==b) ans++;
	if(ans%2==0){
		cout<<"Second"<<endl;
	}else{
		cout<<"First"<<endl;
	}
	
}
