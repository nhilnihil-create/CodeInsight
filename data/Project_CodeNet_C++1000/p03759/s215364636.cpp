#include <iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;


int main() {
	
	vector<ll>vec;
	for(int i=0;i<3;i++)
	{
	    int temp;
	    cin>>temp;
	    vec.push_back(temp);
	}
	sort(vec.begin(),vec.end());
	if((vec[1]-vec[0])==(vec[2]-vec[1]))
	{
	    cout<<"YES"<<endl;
	}
	else{
	    cout<<"NO"<<endl;
	}
	return 0;
}