#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
/*
time:90m23s
wa:
反省:
考察:
*/
int main() {
    int n;
    long long k;
    cin >> n >> k;
    int a, b;
    long long c[100001] = {0};
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        c[a] += b;
    }
    
    for(int i = 1; i <= 100000; i++){
        if(k <= c[i]){
            cout << i << endl;
            break;
        }
        k -= c[i];
    }
    return 0;
}