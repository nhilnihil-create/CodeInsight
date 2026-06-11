#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;

// int prime[1000001];
// vector<ll> primes;

// void soe() {
//     int i,j;
//     for(i=2;i<1000001;i++) prime[i] = 1;
//     for(i=2;i<=sqrt(1000001);i++) {
//         if(prime[i] == 1) {
//             for(j=i*i;j<1000001;j+=i) {
//                 prime[j] = 0;
//             }
//         }
//     }
//     for(i=2;i<1000001;i++) {
//         if(prime[i]) primes.pb(i);
//     }
// }

int d[10];

bool valid(int n) {
    while(n) {
        if(d[n%10]) return false;
        n/=10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int i=1,flag = 0, l, r;
    cin >> s;
    if(s.length() == 2) {
        if(s[0] == s[1]) {
            flag = 1;
            l = 0; r = 1;
        }
    } else {
        while(s[i]) {
            if(s[i+1]) {
                if((s[i] == s[i-1]) || (s[i] == s[i+1]) || (s[i-1] == s[i+1])) {
                    l = i-1 ; r = i+1;
                    flag = 1;
                    break;
                }
            }
            i++;
        }
    }
    if(flag) {
        cout << l+1 << ' ' << r+1;
    } else cout << -1 << ' ' << -1;
    cout << "\n";
    return 0;
}


