#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
P p[100005];
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n);
    cout<<p[n-1].first+p[n-1].second<<endl;
    
}
