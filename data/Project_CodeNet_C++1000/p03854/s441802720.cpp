#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

int main() {
    string s;
    cin >> s;
    bool x=true;
    int i=0;
    while(i<s.size()) {
        if(s.size()-i<5){
            cout << "NO" << endl;
            return 0;
        }

        if(s[i]=='d' && s[i+1]=='r' && s[i+2]=='e' && s[i+3]=='a' && s[i+4]=='m'){
            if(s.size()>i+6){
                if(s[i+5]=='d'){
                    i += 5;
                }
                else if(s[i+5]=='e' && s[i+6]=='r'){
                    if(s.size()>i+7){
                        if(s[i+7]=='d'||s[i+7]=='e') i+=7;
                        else if(s[i+7]=='a') i += 5;
                        else {
                            x=false;
                            break;
                        }
                    }
                    else break;
                }
                else {
                    x=false;
                    break;
                }
            }
            else break;
        }
        else if(s[i]=='e' && s[i+1]=='r' && s[i+2]=='a' && s[i+3]=='s' && s[i+4]=='e'){
            if(s.size()>i+5){
                if(s[i+5]=='d') i+=5;
                else if(s[i+5]=='r') i+=6;
                else if(s[i+5]=='e') i+= 5;
                else {
                    x=false;
                    break;
                }
            }
            else break;
        }
        else {
            x=false;
            break;
        }
    }

    if(x==false) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}