#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int ab=0, bb=0;
    rep(i, n){
        if(s.at(i)=='a' & ab < a+b){
            cout << "Yes" << endl;
            ab+=1;
        }
        else if(s.at(i)=='b' & bb < b & ab < a+b){
            cout << "Yes" << endl;
            bb+=1;
            ab+=1;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}