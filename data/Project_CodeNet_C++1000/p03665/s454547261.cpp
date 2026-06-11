#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <deque>
using namespace std;

int main() {
    //input
    long n,p; cin >> n >> p;
    vector<long> a(n + 1);
    for(int i = 1; i < n + 1; i++) cin >> a[i];

    //compute
    long odd = 0;
    long even = 0;

    for(int i = 1; i < n + 1; i++) {
        if(a[i] % 2 == 0){
            even += 1;
        }else{
            odd += 1;
        }
    }

    //output
    long q;
    q = pow(2,even);
    long r;
    r= pow(2,odd - 1);
  
    if(p == 0){
        if(odd == 0){
            cout << q << endl; 
        }else{
            cout << q * r << endl;
        }
    }else{
        if(odd == 0){
            cout << 0 << endl;
        }else{
            cout << q * r << endl;
        }
    }
}

