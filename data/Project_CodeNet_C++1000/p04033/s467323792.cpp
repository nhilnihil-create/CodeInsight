// Created by ...Lusifer
#include<bits/stdc++.h>
using namespace std;
 
#define pb 		push_back
#define mp 		make_pair
#define prior   priority_queue
#define MOD 	1000000007
#define INF64 	(long long)1e18
#define INF 	(int)1e9
#define PI 		3.1415926535897932384626433832795 
#define ll      long long
#define ld		long double
#define ret     return
#define NUM 	1000001
const int SIZE = 2e5+4;
void fastio(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void solveTest(){
	int a,b;
	cin>>a>>b;
	if(a>0&&b>0){
		cout<<"Positive"<<endl;
	}
	else if(a<=0&&b>=0){
		cout<<"Zero"<<endl;
	}
	else if(a<0&&b<0){
		if(abs(abs(a)-abs(b)+1)%2==0){
			cout<<"Positive"<<endl;
		}
		else {
			cout<<"Negative"<<endl;
		}
	}
	
	return ;
}
 
int main(){
	fastio();

	int t=1;
	//cin>>t;
	while(t--){
		solveTest();
 
	}
	return 0;
}