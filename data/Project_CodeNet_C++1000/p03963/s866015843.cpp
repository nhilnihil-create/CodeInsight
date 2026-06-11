#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define ull unsigned long long
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
int INF = 1001001001;
const int MOD=1e9+7;

int main()
{
  int n,k;
  in n>>k;
  int64_t ans=k*pow((k-1),(n-1));
  
  cout<<ans<<endl;
}
