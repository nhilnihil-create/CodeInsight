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
    int l=s.size();
    l=l-2;
    for(int i=0;i<=l;i++)
    {
          int a[26]={0};
          for(int j=i;j<i+2;j++)
          a[s[j]-'a']++;
          for(int k=0;k<26;k++)
          {
              if(a[k]>1)
              {
                cout<<i+1<<" "<<i+2;
                return 0;
              }
          }
    }
    l++;
    for(int i=0;i<=l;i++)
    {
          int a[26]={0};
          for(int j=i;j<i+3;j++)
          a[s[j]-'a']++;
          for(int k=0;k<26;k++)
          {
              if(a[k]>=2)
              {
                cout<<i+1<<" "<<i+3;
                return 0;
              }
          }
    }
    cout<<"-1 -1";
	return 0;
}