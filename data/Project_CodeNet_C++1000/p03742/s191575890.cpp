
#include <iostream>
using namespace std;

int main() {
	long long x,y;cin>>x>>y;
	long long sub=x-y;
	if(x<y){
		sub*=-1;
	}
	if(sub>=2){
		cout<<"Alice"<<endl;
	}else{
		cout<<"Brown"<<endl;
	}
	return 0;
}
