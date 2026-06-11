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

bool arr[10001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    arr[0]=1;
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        stack<int> v;
        for(int j=0;j+s<=10000;j++){
            if(arr[j]==1){
                v.push(j+s);
            }
        }
        while(!v.empty()){
            int u=v.top();
            v.pop();
            arr[u]=1;
        }
    }
    for(int j=9999;j>=0;j--){
        if(j!=0){
            if(arr[j]==1 && j%10!=0){
                cout<<j<<endl;
                break;
            }
        }
        else{
            cout<<j<<endl;
        }
    }
    return 0;
}
