
/** author: __nishad__ **/
//#pragma GCC optimize(2)
//#pragma GCC optimize(3, "Ofast", "inline")
#include<bits/stdc++.h>
using namespace std;


typedef long long ll ;
typedef vector<ll> vll ;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define precision(k) cout<<setprecision(k)<<fixed;
#define loop(i,a,b) for(ll i=(a);i<=(b);++i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define pb push_back
#define mp make_pair
#define pi 3.14159265358979323
#define endl "\n"

int main()
{
    IOS;

    int n, a, b, count=0;
    cin>>n;

    loop(i, 1, n){
        cin>>a>>b;
        count = count + b - a +1;
    }

    cout<<count;



}



























