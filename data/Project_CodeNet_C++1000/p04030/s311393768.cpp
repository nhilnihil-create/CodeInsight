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
    string s;
    cin>>s;
    char o='0',f='1';
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        ans=ans+o;
        else  if(s[i]=='1')
        ans=ans+f;
        else
        {
            string r="";
            if(ans.size()>0)
            {
            for(int i=0;i<ans.size()-1;i++)
            {
                r=r+ans[i];
            }
            }
            ans=r;
        }
    }
    
    cout<<ans;
	return 0;
}
