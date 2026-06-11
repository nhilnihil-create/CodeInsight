#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int n;
string s;

char diff(char c){
    if (c == 'W')
        return 'S';
    else return 'W';
}

bool judge(char a, char b, char c){
    if (b == 'S'){
        if (s[0] == 'o')
            return a == c;
        else return a != c;
    }else{
        if (s[0] == 'o')
            return a != c;
        else return a == c;
    }
}

bool f(string &p){
    for (int i = 1; i < n; i++){
        if (p[i] == 'S'){
            if (s[i] == 'o'){
                p += p[i - 1];
            }else{
                p += diff(p[i - 1]);
            }
        }else{
            if (s[i] == 'o'){
                p += diff(p[i - 1]);
            }else{
                p += p[i - 1];
            }
        }
    }
    return p[0] == p[n] && judge(p[1], p[0], p[n - 1]);
}

int main(){
    cin >> n;
    cin >> s;

    for (string p : {"SS", "SW", "WS", "WW"}){
        if (f(p)){
            rep(i, n)
                cout << p[i];
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}