#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), a(n*n,0);
    vector<P> ls;
    for(int i=0;i<n;i++){
        cin >> x[i];
        ls.push_back(P(x[i],i));
    }
    sort(ls.begin(),ls.end());
    int l = 0;
    bool ok = true;
    for(int i=0;i<n;i++){
        int m = ls[i].second, cnt = 0;
        a[x[m]-1] = m+1;
        while(cnt < m && l < x[m]-1){
            if(a[l]==0){
                a[l] = m+1;
                cnt++;
            }
            l++;
        }
        if(cnt < m){
            ok = false;
            break;
        }
    }
    for(int i=0;i<n;i++){
        int m = ls[i].second, cnt = 0;
        while(cnt < n-m-1){
            if(a[l]==0){
                if(l < x[m]){
                    ok = false;
                    break;
                }
                a[l] = m+1;
                cnt++;
            }
            l++;
        }
    }
    if(ok){
        cout << "Yes" << endl;
        for(int i=0;i<n*n;i++){
            cout << a[i] << " \n"[i==n*n-1];
        }
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
