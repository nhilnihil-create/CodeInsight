#include<bits/stdc++.h>
#define PI_INT 3.14159265358979323846
#define PI acos(-1.0)
#define LL long long
#define N 100000007
#define MOD 10000007
#define MX numeric_limits<long long>::max();
#define MN numeric_limits<long long>::min();
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define FILL(v, n) fill(v.begin(), v.end(), n);
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL)
#define PRINT(v) for(int i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
#define SCAN(v) for(int i=0; i<n; i++) { int temp; cin>>temp; v.push_back(temp); }
#define SORT(v) sort(v.begin(), v.end())
#define VECT(v) vector<int>v

using namespace std;

int main()
{
    LL a, b;
    cin >> a >> b;

    LL x;
    cin >> x;

    LL ans=0;

    ans+=(b/x);
    ans-=(a/x);

    if(a%x==0) ans++;

    cout<<ans<<endl;
    
    return 0;
}
