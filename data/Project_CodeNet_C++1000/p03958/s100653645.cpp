/*
隣り合う同じ数のペアを最小化する問題である.
->最大となるaの値を見つけて, 他の残りをその間に挟み込んでいく.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int k, t;
    cin >> k >> t;
    
    vector<int> a(t);
    for (int i = 0; i < t; i++) cin >> a[i];
    
    sort(a.rbegin(),a.rend());
    
    int max_a = a[0];
    
    int temp = (max_a - 1 - (k - max_a ) );
    int ans = max(0,temp);
    
    cout << ans << endl;
}
