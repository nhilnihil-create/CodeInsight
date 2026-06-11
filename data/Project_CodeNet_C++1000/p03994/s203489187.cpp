#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;

    int n = s.length();

    ll k;
    cin >> k;

    int che[n];
    for(int i = 0; i < n; i++){
        if(s[i] != 'a'){
            che[i] = 26 - (s[i] - 'a');
        }else{
            che[i] = 0;
        }
    }

    string ans = s;

    for(int i = 0; i < n; i++){
        if(k == che[i]){
            ans[i] = 'a';
            che[i] = 0;
            k = 0;
            break;
        }else if(k > che[i]){
            ans[i] = 'a';
            k -= che[i];
            che[i] = 0;
        }
    }

    int cou = 0;
    for(int i = 0; i < n; i++){
        if(che[i] == 0){
            cou++;
        }
    }

    if(k != 0){
        if(cou == n){
            k %= 26;
            ans[n - 1] = (char)('a' + k);
        }else{
            for(int i = n - 1; i >= 0; i--){
                if(ans[i] != 'a'){
                    ans[i] = (char)(ans[i] + k);
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}