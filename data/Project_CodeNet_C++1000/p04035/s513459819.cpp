#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long int l;
    cin >> n >> l;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int memo = -1;
    for(int i=0; i+1<n; i++){
        if(a[i] + a[i+1] >= l) memo = i+1;
    }

    if(memo == -1){
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << endl;
    for(int i=1; i<memo; i++) cout << i << endl;
    for(int i=n-1; i>memo; i--) cout << i << endl;
    cout << memo << endl;
    return 0;
}