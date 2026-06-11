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
const long long inf = 1e18;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    ld density=0;
    int answater=0;
    int anssugar=0;
    for(int i=0;i<=30;i++){         // 100a water
        for(int j=0;j<=15;j++){     // 100b water
            for(int k=0;k<=1500;k++){       //c sugar
                for(int l=0;l<=750;l++){    //d sugar
                    int water=100*i*a+100*j*b;
                    int sugar=k*c+l*d;
                    if(sugar<=(i*a+j*b)*e && water+sugar<=f && water+sugar>0){

                        if(100.00000*sugar/(water+sugar)>=density){

                            answater=water+sugar;
                            anssugar=sugar;
                            density=100.0000000*sugar/(water+sugar);
                        }
                    }
                }
            }
        }
    }
    cout<<answater<<' '<<anssugar<<endl;
    return 0;
}
