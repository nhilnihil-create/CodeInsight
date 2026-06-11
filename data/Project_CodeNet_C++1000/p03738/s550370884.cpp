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
    string x,y;
    cin>>x>>y;
    int f=0,len1,len2;
    len1=x.length();
    len2=y.length();
    if(len1>len2)
        f=1;
    else if(len1<len2)
        f=-1;
    else{
        for(int i=0;i<len1;i++){
            if(x[i]>y[i]){
                f=1;
                break;
            }
            else if(x[i]<y[i]){
                f=-1;
                break;
            }
        }
    }

    if(f==0)
        cout<<"EQUAL"<<endl;
    else if(f==1)
        cout<<"GREATER"<<endl;
    else
        cout<<"LESS"<<endl;

    return 0;
}
