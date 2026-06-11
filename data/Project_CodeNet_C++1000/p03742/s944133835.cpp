/*g++ main.cpp -o main.out*/
/*./main.out*/
/*std::ios::sync_with_stdio(false);cin.tie(0);*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define Mod 1000000007
#define L_Mod 17100000013

const double eps = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 3.1415926535;

#define ree(n,a) memset(n,a,sizeof(n));

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define red(i,l,u) for(int (i)=(int)(l);(i)>=(int)(u);--(i))

int main()
{
    LL a,b;
    cin>>a>>b;
    if(abs(a-b)==0||abs(a-b)==1)cout<<"Brown"<<endl;
    else cout<<"Alice"<<endl;
    return 0;
}
