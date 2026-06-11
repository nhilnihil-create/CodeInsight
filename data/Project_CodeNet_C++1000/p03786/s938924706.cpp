#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//A=65,a=97

int main() {
    int n;cin >> n;
    vector<int> a(n);for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int l=-1,r=n;
    while(r-l!=1){
        int x=(r+l)/2;
        bool f=true;
        ll sum = a[x];
        for(int i = 0; i < n; i++) {
            if(i==x) continue;
            if(sum*2>=a[i]){
                sum += a[i];
            }
            else {
                f=false;
                break;
            }
        }
        if(f) r=x;
        else l=x;
    }   

    cout << n-r << endl;

    return 0;
}