#include <bits/stdc++.h>
using namespace std;

int main() {
    string a,b,c;
    char next;
    cin >> a >> b >> c;

    next = a[0];
    a.replace(0,1,"");

    while(1){
        if(next == 'a'){
            if(a[0]=='\0'){
                cout << 'A' << endl;
                break;
            }
            next = a[0];
            a.replace(0,1,"");
        }else if(next == 'b'){
            if(b[0]=='\0'){
                cout << 'B' << endl;
                break;
            }
            next = b[0];
            b.replace(0,1,"");
        }else{
            if(c[0]=='\0'){
                cout << 'C' << endl;
                break;
            }
            next = c[0];
            c.replace(0,1,"");            
        }
    }
    return 0;
}