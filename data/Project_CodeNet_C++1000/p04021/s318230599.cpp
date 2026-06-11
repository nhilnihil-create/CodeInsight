#include<bits/stdc++.h>


int main(void) {
    using namespace std;

    long n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    long r = 0;
    for(int i=0; i<n; i++) {
        if(~i&1) r += a[i].second&1;
    }
    cout << r << endl;

}
