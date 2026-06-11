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
    int a,b,c;
    cin>>a>>b>>c;
    int s=0,f=0;
    if(a==7)
    s++;
    else if(a==5)
    f++;
    if(b==7)
    s++;
    else if(b==5)
    f++;
    if(c==7)
    s++;
    else if(c==5)
    f++;
    if(f==2 && s==1)
    cout<<"YES";
    else
    cout<<"NO";
	return 0;
}
