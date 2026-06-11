#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)

typedef long long ll;
typedef long double ld;

int main(){
    int n,a,b; 
    cin >> n >> a >> b;
    string s; cin >> s;
    int san,pass(0),f(1);
    san = a+b;

    for(int i=0;i<n;i++){
        if(pass < san){
            if(s[i]=='a'){
                cout << "Yes" << endl;
                pass++;
                continue;
            }
            if(s[i]=='b' && f<=b){
                cout << "Yes" << endl;
                pass++;
                f++;
                continue;
            }
        }
    cout << "No" << endl;
    }
}