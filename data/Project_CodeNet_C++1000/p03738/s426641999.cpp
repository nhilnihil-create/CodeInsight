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
	string a,b;
	cin>>a>>b;
	if(a.size()>b.size()){
		cout<<"GREATER"<<endl;
	}
	else if(a.size()<b.size()){
		cout<<"LESS"<<endl;
	}
	else {
		int g=0;
		int l=0;
		int e=0;
		for(int i=0;i<a.size();i++){
			if(a[i]<b[i]){
				l=1;
				break;
			}
			else if(a[i]>b[i]){
				g=1;
				break;
			}
		}
		if(l==1){
			cout<<"LESS"<<endl;
		}
		else if(g==1) {
			cout<<"GREATER"<<endl;
		}
		else {
			cout<<"EQUAL"<<endl;
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