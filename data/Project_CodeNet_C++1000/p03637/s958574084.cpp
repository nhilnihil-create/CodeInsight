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
    int n;
    cin>>n;
    int count=0,count2=0,count4=0;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if((k&3)==0){
            count4+=1;
        }
        else if((k&1)==0){
            count2+=1;
        }
        else{
            count+=1;
        }
    }
    int ans=0;
    if(count2==n){
        ans=1;
    }
    else if(count2==0 && count4-count>=-1){
        ans=1;
    }
    else if(count2>0 && count4-count>=0){
        ans=1;
    }
    if(ans==1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
