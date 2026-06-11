#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include <set>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main() {
    int K, T;
    cin >> K >> T;

    vector<int> cake(T);
    for (int i = 0; i < T; i++)
        cin >> cake[i];

    sort(cake.begin(), cake.end(),greater<int>());
  
    int total = 0;
    for (int i = 1; i < T; i++) 
        total += cake[i];
    
    int ans = 0;
    if (cake[0] - 1 > total)
        ans = cake[0] - 1 - total;

    cout << ans << endl;
    
}
