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
int ans = 0;
while(n--)
{
    int l ,r;
    cin>>l>>r;

    ans+=r-l+1;
}
cout<<ans<<endl;

 return 0;
}
