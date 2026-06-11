#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
    int n;
    cin >> n;
    ii arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr,arr+n);
    int num = 0;
    for (int i = 0; i < n; i++) {
        //cout << i << " " << arr[i].first << " " << arr[i].second << "\n";
        num += (abs(arr[i].second-i)%2)==1;
    }
    cout << num/2;
}
