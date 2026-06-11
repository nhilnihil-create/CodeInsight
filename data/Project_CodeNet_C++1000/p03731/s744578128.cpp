#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,t,count=0;
	cin>>n>>t;
	vector<int> tt(n);
	for(int i=0;i<n;i++){
    	cin>>tt.at(i);
    }
	for(int j=1;j<n;j++){
    	if(tt[j]-tt[j-1]>=t){
        	count+=t;
        }else{
        	count+=tt[j]-tt[j-1];
        }
    }
	cout<<t+count;
}
