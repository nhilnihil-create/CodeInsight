#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    map <int , int> a;
    int n;
    for(int i = 0; i < 3; i++){
        cin >> n;
        a[n]+=1;
    }
    n = 0;
    for(auto x : a){
        n++;
    }
    cout << n << endl;
}
