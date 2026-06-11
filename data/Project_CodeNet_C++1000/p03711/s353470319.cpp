#include <bits/stdc++.h>
using namespace std;

int main(){
    int X, Y;
    cin >> X >> Y;

    vector<int> group = {1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};

    if(group.at(X-1) == group.at(Y-1)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}