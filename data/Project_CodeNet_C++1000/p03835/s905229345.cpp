#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define repr(i,x,n) for(int i=x; i<(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define INF 1e9
typedef long long ll;
using VI = vector<int>;
using VB = vector<bool>;
using VS = vector<string>;
using graph = vector<vector<int>>;

int main()
{
int k,s,ans=0;
cin>>k>>s;
for (int i = 0; i <= k; i++)
{
    for (int j = 0; j <= k; j++)
    {
        if (k>=s-i-j&&s-i-j>=0)
        {
            ans++;
        }
        
     
    }
    
}
 cout<<ans<<endl;  
    return 0;
}