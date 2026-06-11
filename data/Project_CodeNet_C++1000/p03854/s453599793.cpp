#include <iostream>
#include <string>
using namespace std;

int main(){
    string S;
    cin >> S;
    string divide[4] = {"dream", "dreamer", "erase", "eraser"};
    int len = S.size();
    string last;
    while(true){
        
        if(len < 5){
            cout << "NO" << endl;
            return 0;
        }
        
        //dream
        last = S.substr(len - 5, 5);
        if(last == divide[0]){
            len = len - 5;
            if(len == 0){
                cout << "YES" << endl;
                return 0;
            }
            continue;
        }

        //erase
        last = S.substr(len - 5,5);
        if(last == divide[2]){
            len = len - 5;
            if(len == 0){
                cout << "YES" << endl;
                return 0;
            }
            continue;
        }

        if(len < 6 ) continue;

         //eraser
        last = S.substr(len - 6,6);
        if(last == divide[3]){
            len = len - 6;
            if(len == 0){
                cout << "YES" << endl;
                return 0;
            }
            continue;
        }
        
        if(len < 7 ) continue;

        //dreamer
        last = S.substr(len - 7,7);
        if(last == divide[1]){
            len = len - 7;
            if(len == 0){
                cout << "YES" << endl;
                return 0;
            }
            continue;
        }

        cout << "NO" << endl;
        return 0;
    }
}