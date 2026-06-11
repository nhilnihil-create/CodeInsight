#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    string s;
    cin>>s;
    int len=s.length();
    for(int i=0; i<len; i++)
    {
        int x=i-1,y=i+1;
        if(x>=0 && y<len)
        {
            if((s[x]==s[i] && s[i]!=s[y])  || (s[x]==s[y] && s[i]!=s[y]) ||
                    (s[y]==s[i] && s[i]!=s[x]) || (s[i]==s[x] && s[i]==s[y])
              )
            {
                cout<<x+1<<" "<<y+1<<endl;
                return 0;
            }
        }
        if(i+1<len && s[i]==s[i+1]){
            {
                cout<<i+1<<" "<<i+2<<endl;
                return 0;
            }
        }

    }
    cout<<"-1 -1"<<endl;

    return 0;
}
