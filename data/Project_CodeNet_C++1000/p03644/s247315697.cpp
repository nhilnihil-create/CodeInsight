#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;

    int ans = int(log2(N));
    cout << int(pow(2, ans)) << endl;

}