#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int arr[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,f=0;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int l=0,r=n-1;
    vector<int>x,y;
    for(int i=n-1; i>=0; i-=2)
    {
        if(i==0)
        {
            x.push_back(arr[i]);
            break;
        }
        x.push_back(arr[i]);
        y.push_back(arr[i-1]);
    }
    reverse(y.begin(),y.end());
    for(auto i:x)
        cout<<i<<" ";
    for(auto i:y)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}
