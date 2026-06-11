#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
#include<utility>
using namespace std;


int main(){
    long long int a, b, c;
    cin >> a >> b >> c;
    int cnt = 0;
    
    if(a == b && b == c && a % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        int ahalf, bhalf, chalf;
        ahalf = a/2;
        bhalf = b/2;
        chalf = c/2;
        a = bhalf + chalf;
        b = ahalf + chalf;
        c = ahalf + bhalf;
        cnt++;
    }
    cout << cnt << endl;
}