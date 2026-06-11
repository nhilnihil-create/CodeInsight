#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[100010] = {0};
    int mini = 1e9,maxi = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[x]++;
        mini = min(mini,x);
        maxi = max(maxi,x);
    }
    if (mini+1<maxi){
        cout << "No";
        return 0;
    }
    if (mini == maxi){
        if (mini == n-1 || mini*2 <= n) cout << "Yes";
        else cout << "No";
    }
    else{
        int numcolours = maxi-arr[mini];
        if (numcolours > 0 && arr[maxi] >= 2*numcolours) cout << "Yes";
        else cout << "No";
    }
}
