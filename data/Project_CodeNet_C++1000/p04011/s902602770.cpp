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
int n,k,x,y;
cin>>n>>k>>x>>y;

if(n>=k)
{
    cout<<(k)*x+(n-k)*y<<endl;
}
else
    cout<<n*x<<endl;
 return 0;
}
