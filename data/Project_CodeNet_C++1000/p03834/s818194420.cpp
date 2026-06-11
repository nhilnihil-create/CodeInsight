#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <cctype>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

int main(){
    vector<char> s(19);
    rep(i,19){
        cin >> s[i];
        if(s[i]==',') s[i]=' ';
    }
    rep(i,19) cout << s[i];
    cout << endl;
}
