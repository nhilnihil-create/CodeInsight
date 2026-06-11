#include<bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define infmx 1e18
#define ff first
#define ss second
#define ll long long
#define pb push_back
typedef pair<int,int>pi;
typedef pair<long long,long long>pll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
const int N=300000;
int mark[33];
bool check(int num)
{
    while(num>0)
    {
        int dig=num%10;
        num/=10;
//        cout<<"dig = "<<dig<<endl;
        if(mark[dig])return 0;
    }
    return 1;
}

int main()
{
    IOS;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        int a;cin>>a;
        mark[a]=1;
    }
    int res=n;
    for(int i=n;;i++)
    {
        if(check(i)){
            res=i;
            break;
        }
    }
    cout<<res<<endl;
}
