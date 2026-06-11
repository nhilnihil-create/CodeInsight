#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B, C;
    cin >> A >> B>> C;
    int a=0, b=0, c=0;
    char x='a';
    while (1){
        if (x=='a'){
            if (a==A.length()){
                cout << "A" << endl;
                return 0;
            }
            x=A.at(a);
            a++;
        }
        else if (x=='b'){
            if (b==B.length()){
                cout << "B" << endl;
                return 0;
            }
            x=B.at(b);
            b++;
        }
        if (x=='c'){
            if (c==C.length()){
                cout << "C" << endl;
                return 0;
            }
            x=C.at(c);
            c++;
        }
    }
}