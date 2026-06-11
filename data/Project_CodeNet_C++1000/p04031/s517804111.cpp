#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
 
using namespace std;

int main() 
{
     int n,ans=1000000000;
     cin>>n;

     int a[n+5];

        for(int i=0; i<n; i++) cin>>a[i];
 
        for(int i=-100;i<=100;i++)
        {
            int cost=0;
            for(int j=0;j<n;j++)
            {
               cost+=(i-a[j])*(i-a[j]);
            }
            ans=min(ans,cost);
        }
         cout<<ans<<endl;
    
}