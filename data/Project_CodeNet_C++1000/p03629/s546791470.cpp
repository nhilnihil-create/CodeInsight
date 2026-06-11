#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
ll len, exi[8000][26], X;
string A, ans;
vector<ll> shiten;
map<char, ll> mp;
int main(void){
    // Your code here!
    cin >> A;
    len = A.length();
    shiten.push_back(len);
    for (ll i = len - 1; i >= 0; i--){
        mp[A[i]]++;
        if (mp.size() == 26){
            shiten.insert(shiten.begin(), i);
            mp.clear();
        }
    }
    for (ll i = 0; i < shiten.size(); i++){
        for (ll j = 0; j < 26; j++){
            bool jud = false;
            for (ll l = X; l < shiten[i]; l++){
                if (A[l] - 'a' != j) continue;
                jud = true;
                break;
            }
            if (jud) continue;
            ans += (char)(97 + j);
            if (shiten[i] == len) break;
            for (ll l = shiten[i];; l++){
                if (A[l] - 'a' != j) continue;
                X = l + 1;
                break;
            }
            break;
        }
    }
    cout << ans << endl;
}
