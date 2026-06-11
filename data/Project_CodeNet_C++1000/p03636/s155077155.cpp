#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    int num = S.size() - 2;
    cout << S.at(0) << num << S.at(S.size() - 1) << endl;
    return 0;
}