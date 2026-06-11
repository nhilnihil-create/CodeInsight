#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;
int main() {
    int st = 0;
    int flag = 0;

    string s;
    cin >> s;
    while (1) {
        if (s.size() == st) {
            flag = 1;
            break;
        }
        else if ((s.size()- st) < 5) {
            break;
        }
        else if (s.substr(st, 5) == "dream") {
            //dreamer と判定
            if (((s.substr((st + 5), 2) == "er") && (s.substr((st + 5), 5)) != "erase")) {
                st += 7;
            }
            //dream　と判定
            else if((s.substr((st+5),2)!="er")||(s.substr((st+5),5)=="erase") ){
                st += 5;
            }
        }
        else if (s.substr(st, 5) == "erase") {
            //eraser と判定
            if (s.substr((st + 5), 1) == "r") {
                st += 6;
            }
            //erase と判定
            else if(s.substr(st+5,1)!="r") {
                st += 5;
            }
        }
        else {
            break;
        }
    }

    if (flag == 1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
