#include <iostream>
using namespace std;
#define debug(x) std::cerr << #x << " = " << (x) << std::endl
typedef long long LL;
const int MAXN = 1e6+17;
int a[MAXN];
int main(int argc ,char const *argv[])
{
    #ifdef noob
    freopen("Input.txt","r",stdin);freopen("Output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    int ans = 0;
    for (int i = 0; i < n-1; ++i)
    {
    	if(a[i]==i+1)
    	{
    		swap(a[i],a[i+1]);
    		ans++;
    	}
    }
    if(a[n-1]==n) ans++;
    cout<<ans<<endl;
    return 0;
}