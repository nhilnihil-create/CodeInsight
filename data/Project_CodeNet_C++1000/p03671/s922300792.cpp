#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z,ans1,ans2,ans3,ans4,ans5;
	cin>>x>>y>>z;
	ans1=x+y;
	ans2=x+z;
	ans3=y+z;
	
	cout<<min(ans1,min(ans2,ans3))<<endl;
	return 0;
	
}
