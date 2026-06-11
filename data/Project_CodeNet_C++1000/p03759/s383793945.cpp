#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
#define pb push_back
#define powerof2 ()
using ll = long long;
const ll M = 1000000007;
using vl = vector<ll>;
using pll =  pair<ll,ll>;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> is;


void answer(){
    int a,b,c;cin>>a>>b>>c;
    if(b-a==c-b)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //int q;
    answer();
    return 0;
}