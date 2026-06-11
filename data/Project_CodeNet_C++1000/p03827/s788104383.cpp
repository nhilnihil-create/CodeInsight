#include <iostream>
using namespace std;

int main() {
	int len;
	cin>>len;
	string str;
	cin>>str;
	int x=0;
	int high=0;
	for(int i=0;i<len;i++){
		if(str[i]=='D'){
			x--;
		}
		else{
			x++;
			if(x>high){
				high=x;
			}
		}
	}
	cout<<high<<endl;
}