#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int ans = 1;
    int flag = 0;
    for(int i=0; i+1<n; i++){
        if(a[i+1] == a[i]) continue;

             if(flag == 0 && a[i] < a[i+1]) flag = 1;
        else if(flag == 0 && a[i] > a[i+1]) flag = 2;
        else if(flag == 2 && a[i] < a[i+1]){ ans += 1; flag = 0; }
        else if(flag == 1 && a[i] > a[i+1]){ ans += 1; flag = 0; }
    }
    cout << ans << endl;
    return 0;
}