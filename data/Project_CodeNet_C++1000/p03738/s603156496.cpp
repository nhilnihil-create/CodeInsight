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
    string a,b;
    cin>>a>>b;
    int ans=-1; // 0=a , 1=draw , 2=b
    if(a.length()>b.length())
        ans=0;
    else if(a.length()<b.length())
        ans=2;
    else{
        ans=1;
        for(int i=0;i<a.length();i++){
            if(b[i]>a[i]){
                ans=2;
                break;
            }
            else if(a[i]>b[i]){
                ans=0;
                break;
            }
        }
    }
    if(ans==0){
        cout<<"GREATER"<<endl;
    }
    else if(ans==1){
        cout<<"EQUAL"<<endl;
    }
    else{
        cout<<"LESS"<<endl;
    }
    return 0;
}
