#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    string s; cin >> s;
    for(int i = 0; i < 12; i++){
        cout << s[i];
        if(i == 3) cout << ' ' ;
    }
    cout << endl;
    return 0;
}