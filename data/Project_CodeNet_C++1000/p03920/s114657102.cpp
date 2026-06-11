#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>
#include <map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll k=((ll)sqrt(1+8*n)+1)/2, r=k*(k+1)/2-n;
    for(ll i=1; i<=k; i++){
        if(i==r) continue;
        cout << i << endl;
    }
    return 0;
}