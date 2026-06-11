#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    //input
    int n; cin >> n;
    long long p_total = 0;
    long long zero = 0;
    vector<long long> a(n + 1);
    vector<long long> b(n + 1);
    for(int i = 1; i < n + 1; i++) cin >> a[i] >> b[i];;
    
    //compute
    reverse(a.begin() + 1 , a.end());
    reverse(b.begin() + 1 , b.end());

    for(int i = 1; i < n + 1; i++){
        p_total += max( zero, (b[i] - ((a[i] + p_total) % b[i])) % b[i]);
    } 

    //output
    cout << p_total << endl;

}