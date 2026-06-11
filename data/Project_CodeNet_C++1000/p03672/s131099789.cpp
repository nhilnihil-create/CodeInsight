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
    len--;
    if(len%2)
        len--;
    while(len>=0)
    {
        int mid=len/2,f=0;
        for(int i=0;i<mid;i++){
            if(s[i]!=s[i+mid])
                f=1;
        }
        if(f)
            len-=2;
        else
            break;

    }
    cout<<len<<endl;

    return 0;
}
