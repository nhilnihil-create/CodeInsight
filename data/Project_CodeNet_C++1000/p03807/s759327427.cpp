#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int count=0;
    int com=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]%2==1) count++;
        else com++;
    }
    if(count%2==0) cout << "YES" << endl;
    else cout << "NO" << endl;
}