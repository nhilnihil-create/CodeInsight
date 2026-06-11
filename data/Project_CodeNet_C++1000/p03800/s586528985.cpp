#include <bits/stdc++.h>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> P;
ll N;
string s;
string ans="";
void judgement(char zero,char one)
{
  //animals.resize(N);
  char animals[100005];
  animals[0]=zero;
  animals[1]=one;
  char lastanimal;
  for (int i = 0; i < N; ++i)
    {
      if(s[i]=='o' && animals[i]=='S')
	{
	  if(i==0)
	    {
	      lastanimal=animals[i+1];
	    }
	  else if(i<N-1)
	    {
	      animals[i+1]=animals[i-1];
	    }
	  else if(i==N-1)
	    {
	      if(animals[i]==lastanimal)
		{
		  if(animals[i-1]==animals[0])
		    {
		      for(int i=0;i<N;i++) ans+=animals[i];
		    }
		}
	    }
	}
      else if(s[i]=='x' && animals[i]=='S')
	{
	  if(i==0)
	    {
	      if(animals[i+1]=='S')
		{
		  lastanimal='W';
		}
	      else
		{
		  lastanimal='S';
		}
	    }
	  else if(i<N-1)
	    {
	      if(animals[i-1]=='S')
		{
		  animals[i+1]='W';
		}
	      else
		{
		  animals[i+1]='S';
		}
	    }
	  else
	    {
	      if(animals[i]==lastanimal)
		{
		  if(animals[i-1]!=animals[0])
		    {
		      for(int i=0;i<N;i++) ans+=animals[i];
		    }
		}
	    }
	}
      else if(s[i]=='o' && animals[i]=='W')
	{
	  if(i==0)
	    {
	      if(animals[i+1]=='S')
		{
		  lastanimal='W';
		}
	      else
		{
		  lastanimal='S';
		}
	    }
	  else if(i<N-1)
	    {
	      if(animals[i-1]=='S')
		{
		  animals[i+1]='W';
		}
	      else
		{
		  animals[i+1]='S';
		}
	    }
	  else
	    {
	      if(animals[i]==lastanimal)
		{
		  if(animals[i-1]!=animals[0])
		    {
		      for(int i=0;i<N;i++) ans+=animals[i];
		    }
		}
	    }
	}
      else if(s[i]=='x' && animals[i]=='W')
	{
	  if(i==0)
	    {
	      lastanimal=animals[i+1];
	    }
	  else if(i<N-1)
	    {
	      animals[i+1]=animals[i-1];
	    }
	  else if(i==N-1)
	    {
	      if(animals[i]==lastanimal)
		{
		  if(animals[i-1]==animals[0])
		    {
		      for(int i=0;i<N;i++) ans+=animals[i];
		    }
		}
	    }
	}

    }
}
int main(void)
{
  cin >> N;
  cin >> s;
  judgement('S','S');
  judgement('S','W');
  judgement('W','S');
  judgement('W','W');
  if(int(ans.size())==0)
    {
      cout << -1 << endl;
    }
  else
    {
      for(int i=0;i<N;i++)
	{
	  cout << ans[i];
	}
      cout << endl;
      return 0;
    }
  return 0;
}
