#include<iostream>
#include<cmath>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<deque>
#include<iomanip>
using namespace std;
#define int            int64_t
#define double         long double
#define nitro          ios_base::sync_with_stdio(false);cin.tie(0);
#define vi             vector<int>
#define di             deque<int>
#define vpii           vector<pair<int,int>>
#define pi             pair<int,int>
#define pub            push_back
#define puf            push_front
#define pob            pop_back
#define pof            pop_front
#define all(a)         a.begin(),a.end()
#define rall(a)        a.rbegin(),a.rend()
#define PI             3.1415926535897932384626433832795
#define read(a)        for(auto& x:a) cin>>x
#define endl           '\n'
#define ln             printf("\n");
#define gap            ' '
#define min3(a,b,c)    min(a, min(b, c))
#define max3(a,b,c)    max(a, max(b, c))
#define MOD            1000000007
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int32_t main()
{
    nitro
    int n,k,s=0;cin>>n>>k;
    int a[n];read(a);
    sort(a,a+n,greater<>());
    for(int i=0;i<k;++i) s+=a[i];
    cout<<s;
}
