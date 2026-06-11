#include <bits/stdc++.h>
using namespace std;

#define gap " "
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ok cout<<"ok"<<endl
#define dbg(x) cout<<(#x)<<" is "<<x<<endl
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N=100009;
int ar[1000];
int main()
{
  //fastio; 
  int n,k,i,r,sum=0;
  scanf("%d %d",&n,&k);

  for(i=0; i<n; i++)
  {
  	scanf("%d",&ar[i]);
  }

  sort(ar,ar+n);

  for(i=n-1,r=1; r<=k; r++,i--)
  {
     sum+=ar[i];
  }
  printf("%d\n",sum);
  return 0;
}