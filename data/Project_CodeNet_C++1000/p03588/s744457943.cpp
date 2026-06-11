#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 2e9+1, ta = 0;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        if(ta < a){
            ans = min(ans, a+b);
        }
    }
    cout << ans << endl;
    return 0;
}