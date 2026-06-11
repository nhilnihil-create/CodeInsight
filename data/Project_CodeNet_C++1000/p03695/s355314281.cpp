#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    int n;cin >> n;
    vector<int> a(8);
    int top=0;
    for(int i = 0; i < n; i++) {
        int x;cin >> x;
        x /= 400;
        if(x<8) a[x]++;
        else top++;
    }
    
    int q=0;
    for(int i = 0; i < 8; i++) {
        if(a[i]>0) q++;
    }
    if(q==0 && top>0){
        cout << 1 << ' ' << top << endl;
        return 0;
    }

    cout << q << ' ' << q+top << endl;

    return 0;
}