#include <iostream>
using namespace std;

int main(){
	int n,a,n1=0,n2=0,n4=0;
	cin>>n;

	while(n--){
		cin>>a;
		if(a%4==0)
			n4++;
		else if(a%2==0)
			n2++;
		else
			n1++;
	}

	int yes=0;

	if(n1==0)
		yes=1;
	else if(n2==0){
		if(n4>=n1-1)
			yes=1;
		else
			yes=0;
	}
	else if(n4>=n1)
		yes=1;
	else
		yes=0;
	//cout<<n1<<n2<<n4<<endl;
	//cout<<yes<<endl;
	yes?cout<<"Yes\n":cout<<"No\n";
}
