#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
ll k,t,a[105];
int main(void){
    cin>>k>>t;
    for(int i=0;i<t;i++) cin>>a[i];
    sort(a,a+t);
    int l=0;
    for(int i=0;i<t-1;i++){
        l+=a[i];
    }
    if(a[t-1]<=l+1){
        cout<<0<<endl;
    }else{
        cout<<a[t-1]-l-1<<endl;
    }
    
}
