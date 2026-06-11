#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n];
    for(int i=0; i<n; i++){
        cin >> p[i]; p[i]--;
    }
    int a[n],b[n];
    for(int i=0; i<n; i++){
        a[i] = i+1;
        b[i] = n-i;
    }
    for(int i=0; i<n-1; i++){
        int q = p[i];
        for(int j=0; j<q; j++) b[j] += n-i;
        for(int j=q+1; j<n; j++) a[j] += n-i;
    }
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout << b[i] << ' ';
    }
    cout << endl;
    return 0;
}
