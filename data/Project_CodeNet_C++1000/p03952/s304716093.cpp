#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    if(x == 1 || x == 2*n-1){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;

        vector<int> ans(2*n);
        ans[n-1] = x-1;
        ans[n]   = x;
        ans[n+1] = x+1;

        int current = 1;
        for(int i=1; i<=2*n-1; i++){
            if(n-1 <= i && i <= n+1) continue;

            if(current == x-1) current += 3;
            ans[i] = current;
            current += 1;
        }
        for(int i=1; i<=2*n-1; i++){
            cout << ans[i] << endl;
        }
    }
    return 0;
}