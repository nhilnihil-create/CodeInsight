#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x;
    cin >> x;

    long long wa = 0;
    int i = 0;
    while(wa < x){
        i++;
        wa += i;
    }

    cout << i << endl;
    return 0;
}