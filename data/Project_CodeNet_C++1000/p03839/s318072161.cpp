#include<bits/stdc++.h>
const int MIN=-1e9;
const int INF=1e9;
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
bool visited[100005];
const int max_N=1e5+10;
int N,K;
ll a[100005];
ll b[100005];
ll ans=0;
int main(void)
{
  cin >> N >> K;
  for(int i=1;i<=N;i++)
    {
      cin >> a[i];
      b[i]=max(a[i],0LL);
    }
  for(int i=1;i<N;i++)
    {
      a[i+1]+=a[i];
      b[i+1]+=b[i];
    }
  for (int i = 1; i <= N-K+1; ++i)
    {
      ll tmp=a[i+K-1]-a[i-1];
      ll tmp2=0;
      
      tmp+=b[i-1];
      //tmp2+=b[i-1];
	
      if(N!=i+K-1)
	{
	  tmp+=(b[N]-b[i+K-1]);
	  tmp2+=(b[N]-(b[i+K-1]-b[i-1]));
	}
      //cout << tmp << ' ' << tmp2 << endl;
      ans=max(ans,tmp);
      ans=max(ans,tmp2);
    }
  cout << ans << endl;
  return 0;
}
