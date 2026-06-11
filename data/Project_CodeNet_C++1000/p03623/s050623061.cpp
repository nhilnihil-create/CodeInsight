#include <iostream>
using namespace std;

int main() {
	int x,a,b;cin>>x>>a>>b;
	int da=abs(x-a);
	int db=abs(x-b);
	if(da>db){
		cout<<'B'<<endl;
	}else{
		cout<<'A'<<endl;
	}
	return 0;
}
