#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
int main(void)
{
    ll n,k;
    cin>>n>>k;
    vector< pair<ll,ll> > arr;

    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr.push_back(pair<ll,ll> (a,b));
    }

    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++)
    {
        k -=arr[i].second;
        if(k<=0) 
        {
            cout<<arr[i].first<<endl;
            return 0;
        }

    }

}