#include <bits/stdc++.h>

using namespace std;

#define fir first
#define sec second
#define ins insert
#define pb push_back
#define po pop_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define PI 3.14159265

typedef long long ll;

const ll max_n = 1e6 + 10 , max_h = 200 , Mod = 1e9 + 7 , inf = 1e18;
ll k , a , b;

void read_input(){
        cin >> k;
}

void solve(){
        a = k % 50;
        b = (k / 50) - a;

        cout << 50 << '\n';
        
        for(int i = 1 ; i <= 50 ; i++){
                if(i <= a)
                        cout <<  b + i + 50 << " ";
                else    
                        cout << b + i - 1 << " ";
        }
}

void output(){
        cout << '\n';
}

int main(){
        IOS;
        read_input();
        solve();
        output();
        return 0;
}