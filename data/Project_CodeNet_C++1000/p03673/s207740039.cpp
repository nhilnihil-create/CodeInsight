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
    int n;cin >> n;
    vector<long> a(n + 1); 
    for(int i = 1; i < n + 1;i++) cin >> a[i];
    deque<int> dq1,dq2;
    
    //compute
    vector<long> b(n + 1); 
    for(int i = 1; i < n + 1;i++){
        if(i % 2 == 1)dq1.push_back(a[i]);
        if(i % 2 == 0)dq2.push_back(a[i]);
        }

    if(n % 2 == 1){
        while( dq2.empty() != 1){
            dq1.push_front(dq2.front());
            dq2.pop_front();
        }
        for(int i = 1; i < n + 1;i++){
            b[i] = dq1.back(); 
            dq1.pop_back();
            }
    }

    if(n % 2 == 0){
        while( dq1.empty() != 1){
            dq2.push_front(dq1.front());
            dq1.pop_front();
        }
        for(int i = 1; i < n + 1;i++){
            b[i] = dq2.back(); 
            dq2.pop_back();
            }
    }


    //output
    for(int i = 1; i < n + 1; i++) cout << b[i] << " " ;
}
