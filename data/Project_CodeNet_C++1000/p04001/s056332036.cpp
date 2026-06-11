
#include <bits/stdc++.h>


using namespace std;
double pi=3.14159265358979323846264338;

string s;
long long ans;
int main(){
	cin>>s;
	ans=0;
	int lnth=s.length();
	int fr,ls;
	int lnth2;

	long long num=stoll(s);
	for(int i=0;i<(1<<lnth-1);i++){
		long long cur=0;
		fr=0;
		lnth2=0;
		ls=0;
		while(ls<lnth){
			if(i&(1<<ls)){
				cur+=stoll(s.substr(fr,ls-fr+1));
				fr=ls+1;
			}
			ls++;
		}
		cur+=stoll(s.substr(fr,lnth-fr+1));
		ans+=cur;
	}
	cout<<ans<<endl;
			
	return 0;
}
