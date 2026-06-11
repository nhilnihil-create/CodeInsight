#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int i,cnt1=0,grade;
	cin>>s;
	int l=s.size();
	for(i=0;i<l;i++){
		if(s[i]=='p'){
			cnt1++;
		}
	}
	grade=l/2-cnt1;
	cout<<grade<<endl;
	return 0;
}