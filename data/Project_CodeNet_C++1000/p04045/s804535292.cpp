#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n, k;
	
	cin>>n>>k;
	
	bool arr[10];
	
	memset(arr, 0, sizeof arr);
	
	for(int i=0; i<k; i++){
		
		int d;
		cin>>d;
		arr[d]=1;
	}
	
	int flag=1;
	for( int num=n; num<=100000; num++)
	{
		flag=1;
		string s= to_string(num);
		for(char c: s){
				if(arr[c-'0']) flag=0; 
			}
		if(flag==1) {
			cout<<num<<endl;
			return 0;
		}
	}
	return 0;
}
