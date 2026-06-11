#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,ans=1;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int ud=0;
    if(n<3){
        cout << 1 << endl;
        return 0;
    }

    for(int i = 1; i < n; i++) {
        if(ud==1){
            if(a[i]<a[i-1]){
                ans++;  
                ud=0;
            }   
        }
        else if(ud==-1){
            if(a[i]>a[i-1]){
                ans ++;
                ud=0;
            }
        }
        else if(ud==0){
            if(a[i]<a[i-1]){
                ud=-1;
            }
            else if(a[i]>a[i-1]){
                ud=1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}