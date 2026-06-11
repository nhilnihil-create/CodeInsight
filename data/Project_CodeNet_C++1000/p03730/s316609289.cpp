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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    for(int i=1;i<=b;i++){
        if(a*i%b==c){
            cout<<"YES"<<endl;
            ans=1;
            break;
        }
    }
    if(ans==0){
        cout<<"NO"<<endl;
    }
    return 0;
}
