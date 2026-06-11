#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long num,z;
    set<long long> list;
    cin >> num;
    for (long long i=0; i<num; i++) {
        cin >> z;
        if (list.count(z)<1) {list.insert(z);}
        else {list.erase(z);}}
    cout << list.size();}