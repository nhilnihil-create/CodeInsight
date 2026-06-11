#include<bits/stdc++.h>
#define MIN -1000000
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
typedef pair<ll,ll> pll;
const int MOD=1e9+7;
bool Tmax[100005];
bool Amax[100005];
int N;
ll T[100005],A[100005],Tmx=0,Amx=0;
int main(void)
{
  ll ans=1;
  memset(Tmax,true,sizeof(Tmax));
  memset(Amax,true,sizeof(Amax));
  cin >> N;
  for (int i = 0; i < N; ++i)
    {
      cin >> T[i];
      if(Tmx==T[i])
	{
	  Tmax[i]=false;
	}
      else
	{
	  Tmx=T[i];
	}
    }
  for (int i = 0; i < N; ++i)
    {
      cin >> A[i];
    }
  for (int i = N-1; i >= 0; i--)
    {
      if(Amx==A[i])
	{
	  Amax[i]=false;
	}
      else
	{
	  Amx=A[i];
	}
    }
  for (int i = 0; i < N; ++i)
    {
      if((Tmax[i] && Amax[i]) &&T[i]!=A[i])
	{
	  ans=0;
	}
      else if((Tmax[i] && A[i]<T[i]) || (Amax[i] && T[i]<A[i]))
	{
	  ans=0;
	}
      else
	{
	  ll Tcand,Acand;
	  if(Tmax[i])
	    {
	      Tcand=1;
	    }
	  else
	    {
	      Tcand=T[i];
	    }
	  if(Amax[i])
	    {
	      Acand=1;
	    }
	  else
	    {
	      Acand=A[i];
	    }
	  ans=(ans*min(Tcand,Acand))%MOD;
	}
	
    }
  cout << ans << endl;
  return 0;
}
