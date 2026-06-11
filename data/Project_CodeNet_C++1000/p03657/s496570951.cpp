#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
    int a, b;
    cin >> a >> b;
    if(a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0){
        cout << "Possible\n";
    } else {
        cout << "Impossible\n";
    }
    return 0;
}