#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,ans=0;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(i<(n-k))continue;
        ans+=a.at(i);
    }
    cout << ans << endl;
    return 0;
}