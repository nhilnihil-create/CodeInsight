#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }

void comb(vector<vector <long long int> > &v){
    for(int i = 0;i <v.size(); i++){
        v[i][0]=1;
        v[i][i]=1;
    }
    for(int k = 1;k <v.size();k++){
        for(int j = 1;j<k;j++){
            v[k][j]=(v[k-1][j-1]+v[k-1][j]);
        }
    }
}


int main(){
    ll N ,A ,B;
    cin >> N >> A >> B;
    if(A > B || (A != B && N < 2)){
        cout << 0 << endl;
        return 0;
    }
    cout << (B - A)* (N - 2) + 1 << endl;
}
