#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000009
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;



int main()
{

int n ;
cin>>n;
if(n==1)
{
    cout<<1<<endl;
    return 0;
}
int ans = 1;
while(ans<=n)
{
    ans*=2;
}
cout<<ans/2<<endl;

 return 0;
}
