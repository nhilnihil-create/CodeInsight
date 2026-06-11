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
int n;
cin>>n;

vector<int> arr(100001,0);
for(int i = 0 ; i< n ;i++)
    {
        int c;
        cin>>c;
        arr[c]++;
    }
int pos =-1;
int ans = 0;
if(ans<arr[0]+arr[1])
{
    ans = arr[0]+arr[1];
    pos=0;
}

if(ans<arr[100000]+arr[100001])
{
    ans = arr[100000]+arr[100000-1];
    pos=100000;
}

for(int index = 1 ;index<100000;index++)
{
    if(ans<arr[index]+arr[index-1]+arr[index+1])
    {
        ans = arr[index]+arr[index-1]+arr[index+1];
        pos = index;
    }
}
    cout<<ans<<endl;


 return 0;
}
