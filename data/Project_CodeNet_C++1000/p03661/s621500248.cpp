/*g++ main.cpp -o main.out*/
/*./main.out*/
/*std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define Mod 1000000007
#define L_Mod 17100000013

const double eps = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 3.1415926535;

#define NO_TLE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ree(n,a) memset(n,a,sizeof(n));

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define red(i,l,u) for(int (i)=(int)(l);(i)>=(int)(u);--(i))

int a[200005];
LL s[200005];

int main()
{
    int n;
    scanf("%d",&n);
    s[0]=0;
    rep(i,n)
    {
        cin>>a[i];
        s[i+1]=s[i]+a[i];
    }
    LL mn=200000000000001;
    rer(i,1,n-1)
    {
        mn=min(mn,abs(s[n]-s[i]-s[i]));
    }
    cout<<mn<<endl;
    return 0;
}
