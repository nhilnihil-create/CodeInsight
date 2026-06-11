#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    string s;
    cin >> s;
    int n = s.length();
    int a = -1, b = -1;
    for(int i=0; i<n-2; i++){
        if(s[i] == s[i+1]){
            a = i + 1;
            b = i + 2;
            break;
        }
        else if(s[i] == s[i+2]){
            a = i + 1;
            b = i + 3;
            break;
        }
    }
    if(s[n-2] == s[n-1]){
        a = n-1;
        b = n;
    }
    cout << a << " " << b << endl;
    return 0;
}