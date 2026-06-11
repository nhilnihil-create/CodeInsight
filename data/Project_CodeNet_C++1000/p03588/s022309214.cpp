#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    int tmp = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(ans < a[i]){
            ans = a[i];
            tmp = i;
        }
    }
    cout << ans + (int)b[tmp] << endl; 

    return 0;
}

