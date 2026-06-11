#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    int a,b,c;cin >> a>> b >> c;
    ll sum=0;
    for(int i = 0; i < b; i++) {
        sum += a;
        if(sum % b == c){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}