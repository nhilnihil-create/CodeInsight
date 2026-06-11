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

int n ,k;
cin>>n>>k;

int ans = 0;
for(int index = 0 ;index < n ;index++)
{
    int x;
    cin>>x;

    ans +=min(2*x,2*abs(x-k));
}
cout<<ans<<endl;

 return 0;
}
