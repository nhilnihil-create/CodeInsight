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

int arr[26];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    int ans=1;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        int k=c-'a';
        if(arr[k]>=1){
            ans=0;
            break;
        }
        else{
            arr[k]+=1;
        }
    }
    if(ans){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}
