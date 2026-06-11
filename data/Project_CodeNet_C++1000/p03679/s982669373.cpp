#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


const int INF = 1e9;
const ll MOD = 1e9 + 7;  

int main(){
    int x,a,b;
    cin >> x >> a >> b;
    if(a >= b) cout <<  "delicious" << endl;
    else if((b - a) <= x) cout << "safe" << endl;
    else cout << "dangerous" << endl;
    return 0;
}

