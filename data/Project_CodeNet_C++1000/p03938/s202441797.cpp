#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n), b(n), p(n);
    for(int i=0; i<n; i++){
        cin >> p[i];
        p[i] -= 1;
        a[p[i]] += i;

        a[i] += (n+1) * (i+1);
        b[i] += (n+1) * (n-i);
    }

    // output
    for(int i=0; i<n; i++){
        cout << a[i];
        if(i == n-1) break;
        cout << " ";
    }
    cout << endl;

    for(int i=0; i<n; i++){
        cout << b[i];
        if(i == n-1) break;
        cout << " ";
    }
    cout << endl;
    return 0;
}