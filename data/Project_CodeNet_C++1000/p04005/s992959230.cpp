#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long int a,b,c;
int main(){
	cin>>a>>b>>c;
	if(a%2==0 || b%2==0 || c%2==0){
		cout<<0;
	}
	else{
		long long int ar[3]={a,b,c};
		sort(ar,ar+3);
		cout<<ar[0]*ar[1];
	}
	return 0;
}