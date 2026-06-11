#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2);
    stable_sort(vec.begin(),vec.end());
    if(vec.at(0)+vec.at(1)==vec.at(2)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}