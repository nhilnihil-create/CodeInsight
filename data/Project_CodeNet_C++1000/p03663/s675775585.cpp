#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
char Ans;

void ask(ll x) {
    cout << "? " << x << endl;
    fflush(stdout);
    cin >> Ans;
}
void ans(ll x) {
    cout << "! " << x << endl;
}

int main() {
    ask(10000000000);
    if(Ans == 'Y') {
        int p = 2;
        for(int i = 0; i <= 9; i++) {
            ask(p);
            if(Ans == 'Y') {
                ans(p/2);
                return 0;
            }
            p *= 10;
        }
    }
    else {
        int s = 0, e = 9;
        int x;
        while(s <= e) {
            int m = (s + e)>>1;

            int p=1;
            for(int i = 0; i < m; i++) p*=10;

            ask(p);

            if(Ans == 'Y') {
                x = m;
                s = m + 1;
            }
            else e = m - 1;
        }

        ll cur = 0;
        for(int i = x; i >= 0; i--) {
            s = (i == x), e = 9;
            int y;
            while(s <= e) {
                int m = (s + e)>>1;

                ll p=1;
                for(int j = 0; j < i + 1; j++) p*=10;

                ask(cur*10 + p*(m + 1) - 1);

                if(Ans == 'Y') {
                    y = m;
                    e = m - 1;
                }
                else s = m + 1;
            }

            int p = 1;
            for(int j = 0; j < i; j++) p*=10;
            cur += y*p;
        }
        ans(cur);
    }
}
