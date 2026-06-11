#include<iostream>
#include<string>
using namespace std;

int main()
{
	// #ifndef IO
	// freopen("input2.txt","r",stdin);
	// #endif

   string o,e;
  cin>>o>>e;
  int l=o.length()+e.length();
  string ans(l,'a');
  for(int i=1;i<=l;i++)
  {
  	if(i&1)
  	{
  		ans[i-1]=o[i/2];
  	}
  	else
  	{
  		ans[i-1]=e[(i/2)-1];
  	}
  }
  cout<<ans;

	return 0;
}