#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    int N;
    cin >> N;
    long long Ta=1,Aa=1;
    int T,A;
    rep(i,N){
        cin >> T >> A;
        long long x = Ta/T;
		long long y = Aa/A;
		if(Ta%T != 0) x++;
		if(Aa%A != 0) y++;
        long long c = max(x,y);
        Ta = c * T;
        Aa = c * A;
    }
    cout << Ta + Aa << endl;

    return 0;
}