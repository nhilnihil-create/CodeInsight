#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i, n) { 
        int b;
        cin >> b;
        a[i] = b - 1;
    }
    int count = 0;
    rep(i, n) {
        if(a[a[i]] == i)
            count++;
    }
    cout << count / 2 << endl;
    return 0;
}