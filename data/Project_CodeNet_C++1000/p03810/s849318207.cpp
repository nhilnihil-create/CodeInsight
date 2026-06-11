#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("First");}else{puts("Second");}
#define MAX_N 200005

// long version
long long int GCD(long long int x, long long int y){
    if(x == 0 && y == 0) return 0;
    if(x>y){
        long long int swap = x;
        x = y;
        y = swap;
    }
    while(true){
        if(y%x==0){
            return x;
        }else{
            long long int amari = y%x;
            y = x;
            x = amari;
        }
    }
}

int main() {
    ll n;
    cin >> n;
    ll a[n];
    rep(i,n){
        cin >> a[i];
    }
    int loop = 0;
    while(true){
        ll sum = 0;
        rep(i,n){
            sum += a[i];
        }
        if(n == 1){
            if(n%2==0)yn;
            return 0;
        }
        if(n == 2){
            if(sum%2==1)yn;
            return 0;
        }
        ll flag = (sum - n) % 2;
        int odd = 0;
        rep(i,n)odd += a[i]%2;
        if(odd>=2){
            if((flag+loop)%2) yn;
            return 0;
        }
        if(odd == 0){
            if(flag==0){
                if(loop)yn;
                return 0;
            }
            rep(i,n){
                if(a[i]==2){
                    if((loop+1)%2)yn;
                    return 0;
                }
            }
            a[0]--;
        }
        if(odd == 1){
            if(flag){
                if((loop+1)%2)yn;
                return 0;
            }
            rep(i,n){
                if(a[i]%2==1){
                    if(a[i]==1){
                        if(loop)yn;
                        return 0;
                    }
                    a[i]--;
                }
            }
            int g = a[0];
            srep(i,1,n){
                g = GCD(g,a[i]);
            }
            rep(i,n){
                a[i] /= g;
            }
        }
        loop = (loop+1)%2;
    }
    return 0;
}


