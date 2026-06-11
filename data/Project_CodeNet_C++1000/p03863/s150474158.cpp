#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    char front = s[0], back = s[s.length()-1];
    int turn = s.length();
    if (front == back){
        turn++;
    }
    if (turn%2 == 0){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }
    return 0;
}