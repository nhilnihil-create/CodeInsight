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
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<char> k;
    k.push(s[0]);

    for(int i=1;i<n;i++){
        if(!k.empty()){
            char c=k.top();
            if(c=='(' && s[i]==')'){
                k.pop();
            }
            else{
                k.push(s[i]);
            }
        }
        else{
            k.push(s[i]);
        }
    }
    int l=0,r=0;    // l=( r=)
    while(!k.empty()){
        char c=k.top();
        if(c==')')
            r+=1;
        else
            l+=1;
        k.pop();
    }
    for(int i=0;i<r;i++){
        cout<<'(';
    }
    cout<<s;
    for(int i=0;i<l;i++){
        cout<<')';
    }
    return 0;
}
