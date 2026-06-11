#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n,a = 0;
    cin >> n;
    for(a = 0;(a+1)*a/2 < n;a++);
    cout << a;
}