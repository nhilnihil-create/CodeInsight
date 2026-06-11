#include <bits/stdc++.h>
using namespace std;
const int inf=100000000;
int main(){
	int n,a,b,acount=0,bcount=0;
	cin>>n>>a>>b;
	vector<char> v(n);
	for(int i=0; i<n; i++){
		cin>>v.at(i);
	}
	for(int i=0; i<n; i++){
		bool Student1=false,Student2=false;
		if(v.at(i)=='a'){
			acount++;
			if(acount+bcount<=a+b) Student1=true;
		}
		else if(v.at(i)=='b'){
			bcount++;
			if(bcount<=b&&acount+bcount<=a+b) Student2=true;
			else bcount--;
		}
		if(Student1||Student2) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}