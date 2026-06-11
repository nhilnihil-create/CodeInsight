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
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1] ){
           if(i==0){
               cout<<"1 2"<<endl;
               ans=1;
           }
           else if(i==s.length()-2){
            cout<<s.length()-2<<' '<<s.length()<<endl;
               ans=1;
           }
           else{
            cout<<i+1<<' '<<i+3<<endl;
             ans=1;
           }
           break;
        }
        if(i==s.length()-2) break;

        else if(s[i]==s[i+2]){
            cout<<i+1<<' '<<i+3<<endl;
            ans=1;
            break;
        }
    }
    if(!ans){
        cout<<"-1 -1"<<endl;
    }
    return 0;
}
