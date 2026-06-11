#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
	vector<int> v(3);
	for(int i=0;i<3;++i)
		cin>>v[i];
	sort(begin(v),end(v));
	if(v[0]==5&&v[1]==5&&v[2]==7){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
	return 0;
}
