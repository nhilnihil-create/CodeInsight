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
string s[3];
int arr[3],cur;
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>s[0]>>s[1]>>s[2];
    while(1)
    {
        if(cur==0)
        {
            if(arr[cur]>=s[cur].length())
            {
                cout<<"A"<<endl;
                break;
            }
            int old=cur;
            if(s[cur][arr[cur]]=='b')
                cur=1;
            else if(s[cur][arr[cur]]=='c')
                cur=2;
            arr[old]++;
        }
        else if(cur==1)
        {

            if(arr[cur]>=s[cur].length())
            {
                cout<<"B"<<endl;
                break;
            }
            int old=cur;
            if(s[cur][arr[cur]]=='a')
                cur=0;
            else if(s[cur][arr[cur]]=='c')
                cur=2;
            arr[old]++;
        }
        else
        {

            if(arr[cur]>=s[cur].length())
            {
                cout<<"C"<<endl;
                break;
            }
            int old=cur;
            if(s[cur][arr[cur]]=='a')
                cur=0;
            else if(s[cur][arr[cur]]=='b')
                cur=1;
            arr[old]++;
        }
    }


    return 0;
}
