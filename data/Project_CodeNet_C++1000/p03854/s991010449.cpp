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

ll checkstring(string s,ll i){
    ll ans=-2;
    if(i<4)
        return -2;
    string p="";
    for(int j=i-4;j<=i;j++){
        p+=s[j];
    }
    if(p=="dream" || p=="erase"){
        ans=1;
        return i-5;
    }
    if(i<5)
        return -2;
    string q="";
    for(ll j=i-5;j<=i;j++){
        q+=s[j];
    }
    if(q=="eraser"){
        ans=1;
        return i-6;
    }
    if(i<6)
        return -2;
    string r="";
    for(ll j=i-6;j<=i;j++){
        r+=s[j];
    }
    if(r=="dreamer"){
        ans=1;
        return i-7;
    }
    if(ans==-2)
        return -2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    ll i=s.length()-1;
    while(1){
        i=checkstring(s,i);
        if(i==-2){
            cout<<"NO"<<endl;
            break;
        }
        else if(i==-1){
            cout<<"YES"<<endl;
            break;
        }
    }
    return 0;
}
