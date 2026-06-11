#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int sumodd = 0;
    for(int i = 0; i < n; i++){
        int j;
        cin >> j;
        if(j % 2 == 1)sumodd += j;
    }
    cout << (sumodd % 2 == 0 ? "YES" : "NO") << "\n";
}