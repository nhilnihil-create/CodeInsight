#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define en "\n"
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define mod 1000000007
#define mpp make_pair
#define mes(a,b) memset((a),(b),sizeof((a))
typedef map<int,int> MI;
typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int a[k];
    int b[10]={0};
    for(int i=0;i<k;i++)
    cin>>a[i],b[a[i]]++;
    bool d=true;
    while(1)
    {
        bool f=true;
        int o=n;
        while(o>0)
        {
            int rem=o%10;
            if(b[rem]>0)
            {
                f=false;
                break;
            }
            o=o/10;
        }
        if(f==false)
        n++;
        else
        break;
    }
    cout<<n;
	return 0;
}
