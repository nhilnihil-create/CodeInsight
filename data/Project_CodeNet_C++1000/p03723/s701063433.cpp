#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll count = 0;
    if(a == b && b == c){
        if(a==1)
            cout << 0 << endl;
        else
            cout << -1 << endl;
    }else{
        int i = 0;
        while(1) {
            if(a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
                cout << i << endl;
                break;
            }
            int tmp_a = a, tmp_b = b, tmp_c = c;
            a = (tmp_b + tmp_c) / 2;
            b = (tmp_a + tmp_c) / 2;
            c = (tmp_a + tmp_b) / 2;
            i++;
        }
    }
        return 0;
}