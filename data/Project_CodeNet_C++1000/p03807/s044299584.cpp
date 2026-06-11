#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1ll<<60;
#include <map>
#include <math.h>

using ll = long long;
using namespace std;

int main(){
    int n, odd=0, even=0; cin >> n;
    rep(i, n){
        int a; cin >> a;
        if(a%2==0) even++;
        else odd++;
    }
    
    int odd_rest, even_rest, odd_quotient=1, even_quotient=1;

    odd_rest = odd%2;
    odd_quotient = odd/2;
    even += odd_quotient;
    odd -= 2*odd_quotient;
    odd = odd_rest;

    while(even_quotient==0){
        even_rest = even%2;
        even_quotient = even/2;
        even = even_rest+even_quotient;
    }

    if(odd==1) out("NO");
    else out("YES");
}