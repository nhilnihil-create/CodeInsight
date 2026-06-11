#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    for(int i = 0;i < a.size();i++){
        cout << a.at(i);
        if(i < b.size())cout << b.at(i);
    }
    cout << endl;
}