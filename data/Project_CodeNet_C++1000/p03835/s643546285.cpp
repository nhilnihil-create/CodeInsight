#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
long long k,s,ans;
int main(){
    ios::sync_with_stdio(0);
    cin>>k>>s;
    for(int i=0; i<=k; i++){
        for (int j=0; j<=k; j++){
            if (s-i-j >=0 && s-i-j<=k) ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}