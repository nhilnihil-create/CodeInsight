#include<iostream>
using namespace std;

int main(){
    string S,T;
    cin >> S;

    int endPos = S.length()-1;
    bool canTransform = true;

    while(1){
        if(endPos >= 4){
            string temp = S.substr(endPos-4, 5);
            if(temp == "dream" || temp == "erase"){
                endPos -= 5;
                continue;
            }
        }
        if(endPos >= 5){
            string temp = S.substr(endPos-5, 6);
            if(temp == "eraser"){
                endPos -= 6;
                continue;
            }
        }
        if(endPos >= 6){
            string temp = S.substr(endPos-6, 7);
            if(temp == "dreamer"){
                endPos -= 7;
                continue;
            }
        }
        if(endPos == -1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        break;
    }




}


