#include <iostream>
#include <string>


using namespace std;

int main(){
    string str;
    string answer;
    cin >> str;
    for(int i = 0; i < str.size(); i += 2){
        answer += str[i];
    }
    cout << answer << endl;
}