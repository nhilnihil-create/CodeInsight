#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    string S;
    cin>>S;
    int a=S.size();
    rep(i,a){
        if(i%2==0){
            cout<<S[i];
        }
    }
    cout<<""<<endl;
}

