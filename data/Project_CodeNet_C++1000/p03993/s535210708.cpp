#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }

    int count=0;
    for(int i=0; i<n; i++){
        if(i+1==a.at(a.at(i)-1)) count++;
    }
    cout << count/2 << endl;
}