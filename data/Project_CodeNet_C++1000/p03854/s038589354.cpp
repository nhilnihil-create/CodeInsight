#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string s;
    cin >> s;
    bool judge=true;
    while(s.size()!=0){
        ll k=0;
        ll n=s.size();

        if(n>=5){
            if(s.substr(n-5)=="erase"||s.substr(n-5)=="dream"){
                k++;
                s.erase(n-5);
            }
        }
        if(n>=6){
            if(s.substr(n-6)=="eraser"){
                k++;
                s.erase(n-6);
            }
        }
        if(n>=7){
            if(s.substr(n-7)=="dreamer"){
                k++;
                s.erase(n-7);
            }
        }
        if(k==0){
            judge=false;
            break;
        }
    }
    if(judge) cout << "YES" << endl;
    else cout << "NO" << endl;
}
