#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    string S;
    cin >> S;
    int len = S.size();
    int gu = 0;
    int pa = 0;
    rep(i,len){
        if (S[i] == 'g') gu++;
        if (S[i] == 'p') pa++;
    }
    cout << (gu - pa) / 2 << endl;
}