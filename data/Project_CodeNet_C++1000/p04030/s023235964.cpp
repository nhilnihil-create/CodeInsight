#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    string s;
    cin >> s;
    string a = "";
    int n = 0;
    rep(i,s.size()){
        if(s[i] == '1')a += '1';
        else if(s[i] == '0')a += '0';
        else if(a.empty())continue;
        else a.erase(a.begin()+a.size()-1);
    }
    cout << a << endl;
    return 0;
}