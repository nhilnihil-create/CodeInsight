#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const long long mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    int n=s.length();
    if((n&1)==0){
        s=s.substr(0,n-2);
        n=n-2;
    }
    else{
        s=s.substr(0,n-1);
        n-=1;
    }
    int ans=0;
    string a,b;
    while(ans==0){
        a=s.substr(0,n/2);
        b=s.substr(n/2,n/2);
        if(a==b)
            ans=1;
        else{
            n-=2;
        }
    }
    cout<<n<<endl;
    return 0;
}
