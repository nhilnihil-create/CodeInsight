#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    if(A % 2 != 0 && B % 2 != 0 && C % 2 != 0){
        cout << min({A * B, B * C, C * A});
    }else{
        cout << 0 << endl;
    }
    return 0;
}