#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nedan(3);
    for(int i=0;i<3;i++){
        cin >> nedan.at(i);
    }
    stable_sort(nedan.begin(),nedan.end());
    cout << nedan.at(0)+nedan.at(1) << endl;
}