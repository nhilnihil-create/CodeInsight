#include<iostream>
#include<vector>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main(){
	string s;
	cin>>s;
	int s_sum = 0;
	int sum=0;
	rep(i,s.size()){
		if(s[i]=='S'){
			s_sum++;
			sum++;
		}else{
			if(s_sum==0){
				sum++;
			}else{
				s_sum--;
				sum--;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}