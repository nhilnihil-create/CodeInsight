#include<iostream>
#define int long long
using namespace std;
bool compare(int u){
	char c;
	cout<<"? "<<u<<endl;
	cin>>c;
	return c=='Y';
}
int nibutan(int l,int r){
	while(r-l){
		int m=(l+r)/2;
		if(!compare(m*10))
			l=m+1;
		else
			r=m;
	}
	return l;
}
signed main(){
	bool f,g;
	f=compare(9);
	if(f){	//9から始まるか1桁
		if(!compare(10)){	//2~9
			int ans=nibutan(2,10);
			cout<<"! "<<ans<<endl;
		}
		else if(compare(1145141919810))	//1
			cout<<"! "<<1<<endl;
		else{
			int juu=10;
			while(compare(juu))
				juu*=10;
			int ans=nibutan(juu/10*9,juu);
			cout<<"! "<<ans<<endl;
		}
	}
	else{
		int juu=100;
		while(!compare(juu-1))
			juu*=10;
		int ans=nibutan(juu/10,juu/10*9);
		cout<<"! "<<ans<<endl;
	}
}