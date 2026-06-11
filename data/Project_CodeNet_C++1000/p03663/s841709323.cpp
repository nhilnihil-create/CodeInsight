#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int getDigit();
string getVal(int);

int main(){
	int dig = getDigit();
	string val = getVal(dig);
	long long ans=0;
	for(int i=0;i<dig;i++) ans=ans*10 + (val[i]-'0');
	cout<<"! "<<(ans+1)<<endl<<flush;
	return 0;
}

int getDigit(){
	int r=10, l=0;
	while(r-l > 1){
		int mid = (l+r)>>1;
		cout<<"? 1";
		for(int i=0;i<mid;i++) cout<<0;
		cout<<endl<<flush;
		char c;cin>>c;
		if(c=='Y') l=mid;
		else r=mid;
	}
	return l+1;
}

string getVal(int len){
	string ss="1000000000";
	for(int i=0;i<len;i++){
		int l=0, r=10;
		while(r-l>1){
			int mid=(l+r)>>1;
			ss[i]='0'+mid;
			cout<<"? "<<ss<<endl<<flush;
			char c;cin>>c;
			if(c=='Y') r=mid;
			else l=mid;
		}
		ss[i]='0'+l;
	}
	return ss;
}