#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main()
{
    int n;cin >>n;
    int a[n];bool b[n];
    for(int i=0;i<n;i++){
        int k;cin >>k;
        k--;a[i]=k;
        b[i]=true;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(b[i]&&a[a[i]]==i){
                ans++;
                b[a[i]]=false;
        }
    }
    cout << ans << endl;
    return 0;
}
