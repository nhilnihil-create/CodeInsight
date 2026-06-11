#include <bits/stdc++.h>
using namespace std;

int main(){
    int i, x, sum = 0;
    cin >> x;
    i = 1;
    while(sum < x){
        sum += i;
        i++;
    }
    cout << i-1;
    return 0;
}