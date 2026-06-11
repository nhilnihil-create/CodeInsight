#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define PI acos(-1.0)
#define MOD 2520
#define E 1e-12
using namespace std;
typedef long long ll;
const int MAXN=500000+5;//最大元素个数
char ans[MAXN]; 
 string s;
   int n;
int solve(char ch1,char ch2)
{
  ans[0]=ch1;
  ans[1]=ch2;
  for(int i=1;i<n;i++)
  {
  	if(s[i]=='o')
	{
		if(ans[i]=='S')
		ans[i+1]=ans[i-1];
		else
		{
			if(ans[i-1]=='W')
		    ans[i+1]='S';
		    else
			ans[i+1]='W';
		}
	}
	else  if(s[i]=='x')
	{
		if(ans[i]=='W')
		ans[i+1]=ans[i-1];
		else
		{
			if(ans[i-1]=='W')
		    ans[i+1]='S';
		    else
			ans[i+1]='W';
		}
	}
  }
  char temp;
    if(s[0]=='o')
    {
    	if(ans[0]=='S')
    		temp=ans[1];
		else
		{
			if(ans[1]=='W')
		    temp='S';
		    else
			temp='W';
		}
    }
    else
	{
		if(ans[0]=='W')
    		temp=ans[1];
		else
		{
			if(ans[1]=='W')
		    temp='S';
		    else
			temp='W';
		}
	}
    if(ans[n]==ans[0]&&temp==ans[n-1]) return 1;
    else return 0;
  	
}
int main()
{
  
    scanf("%d",&n);
   
    cin>>s;
    if(solve('S','S')==1)
	{
		
		for(int i=0;i<n;i++)
			cout<<ans[i];
		//cout<<ans<<endl;
	}
	else if(solve('S','W')==1)
	{
		for(int i=0;i<n;i++)
			cout<<ans[i];
		//cout<<ans<<endl;
	}
	else if(solve('W','S')==1)
	{
		for(int i=0;i<n;i++)
			cout<<ans[i];
		//cout<<ans<<endl;
	}
	else if(solve('W','W')==1)
	{
		for(int i=0;i<n;i++)
			cout<<ans[i];
		//cout<<ans<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
    return 0;
}
