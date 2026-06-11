#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <iomanip>
#include <limits.h>

using namespace std;    
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const bool DEBAG = false;


int main(){

    ll H, W;
    cin >> H >> W;

    vector<string> s(H);
    for(int i = 0; i < H; i++){
        cin >> s[i];
    }    
    
    vector<ll> cnt(26);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cnt[ s[i][j] - 'a' ] ++;
        }
    }


    if(H % 2 == 0 && W % 2 == 0){
        for(int i = 0; i < 26; i++){
            cnt[i] = cnt[i] % 4;
        }
        ll ans = accumulate(all(cnt), 0ll);
        if(ans > 0){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }  
    else if(H % 2 == 0 || W % 2 == 0){

        ll min = 0;
        for(int i = 0; i < 26; i++){
            cnt[i] = cnt[i] % 4;
        }
        for(int i = 0; i < 26; i++){
            if(cnt[i] >= 2){
                min += 2;
            }
            cnt[i] = cnt[i] % 2;
        }
        ll ans = accumulate(all(cnt), 0ll);
        if(ans > 0){
            cout << "No" << endl;
        }
        else if(H % 2 == 0){
            if(min <= H){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
        else if(W % 2 == 0){
            if(min <= W){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    else{

        ll min = 0;
        for(int i = 0; i < 26; i++){
            cnt[i] = cnt[i] % 4;
        }
        for(int i = 0; i < 26; i++){
            if(cnt[i] >= 2){
                min += 2;
            }
            cnt[i] = cnt[i] % 2;
        }
        ll ans = accumulate(all(cnt), 0ll);
        if(ans != 1){
            cout << "No" << endl;
        }
        else if(H + W - 1 >= min){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

}