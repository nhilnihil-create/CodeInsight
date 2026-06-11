#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main(){
    string s;
    cin >> s;
    if(s.size() < 4){
        cout << "No" << endl;
        return 0;
    }
    if(s.substr(0,4) == "YAKI"){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
