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
string s[5000];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int r,c;
    cin>>r>>c;
    for(int i=0; i<r; i++)
    {
        cin>>s[i];
    }
    for(int i=0; i<c+2; i++)
    {
        cout<<"#";
    }
    cout<<endl;
    for(int i=0; i<r; i++)
    {
        cout<<"#";
        cout<<s[i];
        cout<<"#"<<endl;
    }
    for(int i=0; i<c+2; i++)
    {
        cout<<"#";
    }
    cout<<endl;
    return 0;
}
