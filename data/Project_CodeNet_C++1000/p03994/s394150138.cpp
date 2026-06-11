#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string str;
    ll N;
    cin >> str >> N;
    for(int i = 0; i < str.size(); i++){
        if(str[i] != 'a' && ('a' + 26) - str[i] <= N){
            N -= ('a' + 26) - str[i];
            str[i] = 'a';
        }
    }
    N = N % 26;
    if(N > 0){
        str.back() = ((str.back() + N) - 'a') % 26 + 'a';
    }
    cout << str << endl;
}