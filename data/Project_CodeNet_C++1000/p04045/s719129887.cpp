#include<bits/stdc++.h>
using namespace std;
bool qwq[10];
bool truly(int w)
{
	while(w>0)
	{
		if(!qwq[w%10]) return true;
		w/=10;
	}
	return false;
}
int main()
{
	memset(qwq,true,sizeof(qwq));
	int t,k;
	cin>>t>>k;
	for(int i=0;i<k;i++)
	{
		int q;
		cin>>q;
		qwq[q]=false;
	}
	while(truly(t))
	{
		t++;
	}
	cout<<t;
}