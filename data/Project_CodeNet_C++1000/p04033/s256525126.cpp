#include<iostream>
#include<map>
#include<vector>
 
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	if(b>=0&&a<=0)
		cout<<"Zero\n";
	else{
		if(a>0&&b>0)
			cout<<"Positive\n";
		else{
			int count=(-a)+b+1;
			if(count&1)
				cout<<"Negative\n";
			else
				cout<<"Positive\n";
		}
	}
	return 0;
}
