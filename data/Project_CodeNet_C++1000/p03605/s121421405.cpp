#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
	int n,mi=0,ma=0,ans=0;
	cin>>n;
	if(n/10==9||n%10==9){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
	
}