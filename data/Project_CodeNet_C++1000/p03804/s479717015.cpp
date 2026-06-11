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
    int n,m;
    cin>>n>>m;
    vector<string> a;
    vector<string> b;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        a.pb(s);
    }
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        b.pb(s);
    }
    int count=0;
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            int ans=1;
            for(int p=0;p<m;p++){
                for(int q=0;q<m;q++){
                    if(a[i+p][j+q]!=b[p][q]){
                        ans=0;
                    }
                }
            }
            if(ans==1){
                count=1;
            }
        }
    }
    if(count==1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
