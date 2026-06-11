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
    int a,b,c,d,cnt=0;
    cin>>a>>b>>c>>d;
    for(int i=a;i<=b;i++){
        if(i>=c && i<=d)
            cnt++;
    }
    cnt--;
    cnt=max(cnt,0);
    cout<<cnt<<endl;

    return 0;
}
