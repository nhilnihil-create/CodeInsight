#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
    //input
    int n;cin >> n;
    vector<int> a(n);
    vector<int> c(100);
    for(int i = 0; i < 100; i++) c[i]= 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    //compute
    int counter = 0;
    int mi,ma,sum;
    mi = 0;
    ma = 0;
    sum = 0;

    for(int i = 0; i < n;i++){
        if(a[i] >= 1 && a[i] <= 399 ){
            c[0] = 1;
        }else if(a[i] >= 400 && a[i] <= 799){
            c[1] = 1;
        }else if(a[i] >= 800 && a[i] <= 1199){
            c[2] = 1;
        }else if(a[i] >= 1200 && a[i] <= 1599){
            c[3] = 1;
        }else if(a[i] >= 1600 && a[i] <= 1999){
            c[4] = 1;
        }else if(a[i] >= 2000 && a[i] <= 2399){
            c[5] = 1;
        }else if(a[i] >= 2400 && a[i] <= 2799){
            c[6] = 1;
        }else if(a[i] >= 2800 && a[i] <= 3199){
            c[7] = 1;
        }else if(a[i] >= 3200){
            counter += 1;
        }
    }

    for(int i = 0; i < 8; i++) {
        sum += c[i];
    }

    ma = sum + counter;
    mi = max(sum , 1);

    //output
    cout << mi << " " << ma << endl;

}