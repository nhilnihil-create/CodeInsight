#include <bits/stdc++.h>
#define pi acos(-1)
#define MOD 998244353
#define MAX 100000
#define inf 1e9+10
#define print(a) cout<< #a <<" --> "<<(a)<<endl
#define Endl endl
#define endk endl
#define Endk endl
#define fileinput freopen("altsub - Copy.txt","r",stdin)
#define fileoutput freopen("max-med.txt","w",stdout)
typedef std::vector<int> vi;
typedef std::vector<vi > vvi;
typedef std::pair<int,int> pii;
typedef long long ll;

 using namespace std;

ll a[MAX+4],b[MAX+4];

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }

    ll x=(a[n-1]/b[n-1])+1; //print(x);
    x=b[n-1]*x-a[n-1]; //print(x);
    if(a[n-1]%b[n-1]==0) x=0;

    for(int i=n-2;i>=0;i--)
    {
        ll A=a[i]; ll B=b[i]; //if(A==B) continue;
        ll d=(x+A)/B;
        if(B*d-A>=x) x=B*d-A;
        else x=B*(d+1)-A;
    }
    cout<<x<<endl;;

}