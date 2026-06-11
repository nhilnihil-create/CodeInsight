#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int groups = 1;
    char currentStone = s[0];
    for(int i=1; i<s.length(); i++){
        char nextStone = s[i];
        if(currentStone != nextStone){
            currentStone = nextStone;
            groups++;
        }
    }
    cout << (groups-1) << '\n';
}