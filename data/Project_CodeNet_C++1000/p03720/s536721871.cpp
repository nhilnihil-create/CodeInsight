#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long cities,roads,a,b;
    cin >> cities >> roads;
    long long grid[cities]={0};
    for (long long i=0; i<roads; i++){
        cin >> a >> b;
        grid[a-1]++;
        grid[b-1]++;}
    for (long long i=0; i<cities; i++){
        cout << grid[i];
        if (i<cities-1) {cout << "\n";}}}