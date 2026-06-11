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

LL a[55];

int main()
{
    a[0]=49;
    rer(i,1,49)a[i]=0;
    LL k;
    cin>>k;
    cout<<50<<endl;
    if(k==0)
    {
        cout<<a[0];
        rer(i,1,49)cout<<' '<<a[i];
        cout<<endl;
    }
    else
    {
        rep(i,50)a[i]=i;
        LL r=(k-1)/50;
        rep(i,50)a[i]+=r;
        LL t=k%50;
        if(t==0)
        {
            rep(i,50)a[i]++;
            cout<<a[0];
            rer(i,1,49)cout<<' '<<a[i];
            cout<<endl;
        }
        else if(t>0)
        {
            while(t--)
            {
                sort(a,a+50);
                a[0]+=50;
                rer(i,1,49)a[i]--;
            }
            cout<<a[0];
            rer(i,1,49)cout<<' '<<a[i];
            cout<<endl;
        }

    }

    return 0;
}
