#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int x, y;
    cin >> x >> y;
    vector<int> group1 = {1, 3, 5, 7, 8, 10, 12};
    vector<int> group2 = {4, 6, 9, 11};
    vector<int> group3 = {2};
    int label1, label2;
    for(int a : group1){
        if(x == a) label1=1;
        if(y == a) label2=1;
    }
    for(int a : group2){
        if(x == a) label1=2;
        if(y == a) label2=2;
    }
    for(int a : group3){
        if(x == a) label1=3;
        if(y == a) label2=3;
    }
    if(label1 == label2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
