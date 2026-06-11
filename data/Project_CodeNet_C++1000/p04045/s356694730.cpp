#include <iostream>
#include <string> 
using namespace std;

int has_no(string &str,bool arr[]){
	for(int i=0;i<str.length();i++){
		if(arr[str[i]-'0'])return false;
	}
	return true;
}
int main() {
	int num,n;
	cin>>num>>n;
	
	bool arr[10] ={};
	for(int i=0;i<n;i++){
		int n2;
		cin>>n2;
		arr[n2] =true;
	}
	for(int j=num;j<100000;j++){
		string str =to_string(j);
		if(has_no(str,arr)){
			cout<<str<<endl;
			break;
		}
	}
}