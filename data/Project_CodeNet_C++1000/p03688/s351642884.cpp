#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define db double
#define ll long long
main(){  
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    if (v.back() - v[0] >= 2){
        cout << "No";
        return 0;
    }
    if (v[0] != v.back()){
        int L = 1;
        for (int i=1; i < v.size(); i++) if (v[i] == v[0]) L++;
        int other = v[0]+1 - L;
        if (other <= 0){
            cout << "No";
            return 0;
        }
        if (2*other <= n-L){
            cout << "Yes";
            return 0;
        }
        cout << "No";
        return 0;
    }
    if (v[0] == n-1){
        cout << "Yes";
        return 0;
    }
    if (2*v[0] <= n){
        cout << "Yes";
    }
    else cout << "No";
}