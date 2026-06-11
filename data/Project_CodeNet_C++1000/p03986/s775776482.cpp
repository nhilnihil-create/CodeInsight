#include<iostream>
#include<string>
using namespace std;
string str;
int main(){
	cin>>str;
	int cur=0;
	int num1=0; int num2=0;
	int len=str.size();
	int ans=0;
	while(cur<len){
		if(str[cur]=='S') num1++;
		if(str[cur]=='T'){
			if(num1>0){
				num1--;
				ans++;
			}
		}
		cur++;
	}
	cout<<len-2*ans<<endl;
	return 0;
} 