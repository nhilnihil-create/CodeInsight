#include<bits/stdc++.h>
using namespace std;
int getColor(int n){
	if( n<=399 )return 0;
	else if( n<=799 )return 1;
	else if( n<=1199 )return 2;
	else if( n<=1599 )return 3;
	else if( n<=1999 )return 4;
	else if( n<=2399 )return 5;
	else if( n<=2799 )return 6;
	else if( n<=3199 )return 7;
	else return -1;
}
int main(){
	
	int n;cin>>n;
	int a[n];

	unordered_set<int> st;

	int free = 0;

	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]=getColor(a[i]);

		if(a[i]==-1)free++;
		else st.insert(a[i]);
	}
	//get min
	if(st.size()==0)cout<<1<<endl;
	else cout<<st.size()<<" ";

	//get max
	cout<<st.size()+free<<endl;


	return 0;

}