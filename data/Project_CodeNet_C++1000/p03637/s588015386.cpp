#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int a[n];
    int even = 0, four = 0;
    for(int i = 0;i < n; i++){
        cin >> a[i];
        if(a[i] % 4 == 0) four++;
        else if (a[i] % 2 == 0 && a[i] % 4 != 0) even++;
    }
    if(four + even / 2 >= n / 2){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

    return 0;
}