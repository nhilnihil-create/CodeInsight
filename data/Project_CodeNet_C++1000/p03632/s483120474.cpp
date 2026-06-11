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
int a,b,c,d;
cin>>a>>b>>c>>d;

a= max(a,c);
b=min(b,d);

if(a<b)
    cout<<b-a<<endl;
else
    cout<<0<<endl;
 return 0;
}
