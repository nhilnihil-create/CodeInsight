#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[100000],b[10]={0};
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(a[i]%4==0) b[4]++;
        else if(a[i]%2==0) b[2]++;
        else b[0]++;
    }

    if(b[2]>0) b[0]++;
    if(b[4]+1>=b[0]) cout << "Yes";
    else cout << "No";
}