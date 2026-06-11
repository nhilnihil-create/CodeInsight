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

int arr[n+1];
vector<int> deja(n+1,0);
for(int index = 1 ;index <= n;index++)
    cin>>arr[index];

int next = 1;
int ans = 0;

while(!deja[next]&&next!=2)
{
    deja[next ] =true;
    next = arr[next];
    ans++;
}

if(next == 2)
    cout<<ans<<endl;
else
    cout<<-1<<endl;
 return 0;
}
