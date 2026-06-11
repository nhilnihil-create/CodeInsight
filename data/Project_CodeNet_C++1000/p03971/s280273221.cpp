#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;

int main(){
    int n, a, b, sum = 0, ovsum = 0;
    string s;
    cin >> n >> a >> b >> s;
    rep(i, s.size()){
        if(sum < a + b && s[i] == 'a'){
            cout << "Yes" << endl;
            sum++;
        }else if(s[i] == 'b' && sum < a + b && ovsum < b){
            cout << "Yes" << endl;
            sum++; ovsum++;
        }else{
            cout << "No" << endl;
        }
    }
}