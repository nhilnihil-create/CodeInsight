#include<iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    for(int i=0;i<12;i++){
        cout << str[i];
        if(i==3) cout << ' ';
    }
    cout << endl;
}