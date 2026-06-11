#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main()
{
    int n;cin>>n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
    {   
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(all(a));
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(a[i].second%2!=i%2);
    }
    cout<<ans/2<<endl;
}