#include <bits/stdc++.h>
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define divceil(A, B) ((A + (B - 1)) / B)
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define CERR if(false) cerr

typedef long long ll;

using namespace std;

int main(){

    int n;
    string s;
    cin >> n;
    cin >> s;

    int index = 0;

    vector<int> h;

    while(index <= n - 1){
        if(index != n - 1 && s[index] == s[index + 1]){
            h.pback(2);
            index += 2;
        }else{
            h.pback(1);
            index++;
        }
    }

    ll ans;
    int state;

    if(h[0] == 1){
        ans = 3;
        state = 1;
    }else{
        ans = 6;
        state = 2;
    }

    for(int i = 1; i < h.size(); i++){
        if(state == 1){
            if(h[i] == 1){
                ans = (ans * 2) % MODN;
            }else{
                ans = (ans * 2) % MODN;
                state = 2;
            }
        }else{
            if(h[i] == 1){
                state = 1;
            }else{
                ans = (ans * 3) % MODN;
            }
        }
    }

    
    cout << ans << endl;
    return 0;
}