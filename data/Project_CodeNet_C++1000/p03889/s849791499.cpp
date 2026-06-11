#include<iostream>
#include<cstring>
using namespace std;
string t,ans;
char change(char k)
{
	if(k=='b') return 'd';
	if(k=='d') return 'b';
	if(k=='p') return 'q';
	if(k=='q') return 'p';
}
int main()
{
	cin>>t;
	int lent=t.length();
	ans=t;
	for(int i=0;i<lent;i++)
	{
		ans[i]=change(t[lent-i-1]);
	}
	if(t==ans) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}

