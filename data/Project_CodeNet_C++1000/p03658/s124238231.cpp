#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int N ,K;
    cin >> N >> K;
    int l;
    vector<int> L(N);
    for(int i=0;i<N;i++){
        cin >> l ;
        L.at(i) = l;
    }
    sort(L.begin(), L.end());
    reverse(L.begin(), L.end());
    int max_lengh=0;
    for(int i=0;i<K;i++){
        max_lengh = max_lengh + L.at(i) ;
    }
    cout << max_lengh << endl;
}