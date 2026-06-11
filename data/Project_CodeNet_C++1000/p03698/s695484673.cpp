#include <bits/stdc++.h>
using namespace std;

int main(){

    string S;
    cin >> S;

    map<char, int> dict;
    for (int i=0; i<S.size(); i++){
        dict[S.at(i)]++;

        if (dict[S.at(i)] > 1){
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;
    return 0;
}