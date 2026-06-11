#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    int ans = arr[n - 1].first + arr[n - 1].second;

    cout << ans << endl;

}