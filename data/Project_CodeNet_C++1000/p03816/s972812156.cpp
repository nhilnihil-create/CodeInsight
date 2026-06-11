#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    set<int> s(a.begin(),a.end());
    int k=s.size();
    if((n-k)%2==0) cout<<k<<endl;
    else cout<<k-1<<endl;
}