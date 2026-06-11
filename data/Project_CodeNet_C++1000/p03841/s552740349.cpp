#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<long long int,int>> x(n);
    for(int i=0; i<n; i++){
        cin >> x[i].first;
        x[i].first -= 1;
        x[i].second = i+1;
    }
    sort(x.begin(),x.end());

    vector<int> ans(n*n);
    long long int pos = 0;
    for(int i=0; i<n; i++){
        ans[x[i].first] = x[i].second;
        for(int j=1; j<x[i].second; j++){
            while(ans[pos] != 0) pos += 1;
            if(pos > x[i].first){
                cout << "No" << endl;
                return 0;
            }
            ans[pos] = x[i].second;
        }
    }

    reverse(x.begin(),x.end());
    pos = n*n-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-x[i].second; j++){
            while(ans[pos] != 0) pos -= 1;
            if(pos < x[i].first){
                cout << "No" << endl;
                return 0;
            }
            ans[pos] = x[i].second;
        }
    }

    cout << "Yes" << endl;
    for(int i=0; i<n*n; i++){
        cout << ans[i];
        if(i == n*n-1) break;
        cout << " ";
    }
    cout << endl;
    return 0;
}