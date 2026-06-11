#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    if (s.size()==2){
        if (s.at(0)==s.at(1)){
            cout << 1 << " " << 2 << endl;
        } else {
            cout << -1 << " " << -1 << endl;
        }
        return 0;
    }
    for (int i=0; i<s.size()-2; i++){
        if (s.at(i)==s.at(i+1) || s.at(i+1)==s.at(i+2) || s.at(i+2)==s.at(i)){
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}