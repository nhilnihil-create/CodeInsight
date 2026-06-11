#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n = 0, a = 0, b = 0;
    cin >> n >> a >> b;
    char temp;

    ll a_temp = 0, b_temp = 0, all_temp = 0;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(temp == 'a') {
            if(all_temp < (a + b)) {
                cout << "Yes\n";
                all_temp++;
            }
            else {
                cout << "No\n";
            }
        }
        else if(temp == 'b') {
            if(all_temp < (a + b)) {
                if(b_temp < b) {
                    cout << "Yes\n";
                    b_temp++;
                    all_temp++;
                }
                else {
                    cout << "No\n";
                }
            }
            else {
                cout << "No\n";
            }
        }
        else {
            cout << "No\n";
        }
    }
    
    return 0;
}