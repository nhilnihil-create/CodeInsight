#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int sum = 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int make = sum/n;
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i <  n; i++) {
        ans1 += pow(abs(arr[i] - make) , 2);
    }
    make++;
    for (int i = 0; i < n; i++) {
        ans2 += pow(abs(arr[i] - make) , 2);
    }
    cout << min(ans1 , ans2) << endl;
}