#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    if(a[n-1] >= a[0] + 2){
        cout << "No" << endl;
        return 0;
    }

    int unique = upper_bound(a.begin(),a.end(),a[0]) - a.begin();
    if((n - unique == 0 && a[0] != n-1 && a[0] > (n-1+1)/2)
    ||  n - unique == 1// by definition of "unique"
    || (n - unique >= 2 && a[0] + 1 > unique + (n - unique) / 2)
    || (n - unique >= 2 && a[0]     < (unique - 1) + 1)){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}