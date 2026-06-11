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
const int MAX = 1e5;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string x,a,b,c,d;
int len;
bool test(int pos,string y)
{
    if(pos+y.length()-1>=len)
        return 0;
    for(int i=0; i<y.length(); i++)
        if(x[pos+i]!=y[i])
            return 0;
    return 1;
}
void recur(int pos)
{
    if(pos==len)
    {
        cout<<"YES"<<endl;
        exit(0);
    }
    if(test(pos,a))
        recur(pos+a.length());
    if(test(pos,b))
        recur(pos+b.length());
    if(test(pos,c))
        recur(pos+c.length());
    if(test(pos,d))
        recur(pos+d.length());
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    a="dream",b="erase",c="dreamer",d="eraser";
    cin>>x;
    len=x.length();
    recur(0);


    cout<<"NO"<<endl;

    return 0;
}
