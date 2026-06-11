#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a(n+2,-1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int la=0,ans=0;
    for(int i=1;i<=n+1;i++){
        if(a[i]!=i){
            ans+=(la+1)>>1;
            la=0;
        }
        else{
            la++;
        }
    }
    cout << ans << endl;
    return 0;
}