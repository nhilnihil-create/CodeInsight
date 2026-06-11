#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n, t;
    cin >> n >> t;
    vector<i64> v;
    for(int i=0;i<n;++i){
        int a;
        cin >> a;
        v.push_back(a);
    }

    vector<i64> cummax(n+1);
    for(int i=n-1;i>=0;--i){
        cummax[i] = max(cummax[i+1], v[i]);
    }

    int cnt = 0, maxi = 0;
    for(int i=0;i<n;++i){
        int d = cummax[i+1] - v[i];
        if(d > maxi){
            cnt = 1;
            maxi = d;
        }else if(d == maxi){
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}