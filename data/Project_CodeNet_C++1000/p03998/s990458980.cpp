#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
int main(void){
    string S_A,S_B,S_C;
    cin >> S_A >> S_B >> S_C;
    queue<char> a,b,c;
    for(int i=0;i<S_A.size();i++){
        a.push(S_A[i]);
    }
    for(int i=0;i<S_B.size();i++){
        b.push(S_B[i]);
    }
    for(int i=0;i<S_C.size();i++){
        c.push(S_C[i]);
    }
    char next = 'a';
    char ans;
    while(1){
        if(next == 'a'){
            if(a.empty()){
                cout << "A" << endl;
                return 0;
            }
            next = a.front();
            a.pop();
        }
        else if(next == 'b'){
            if(b.empty()){
                cout << "B" << endl;
                return 0;
            }
            next = b.front();
            b.pop();
        }
        else{
            if(c.empty()){
                cout << "C" << endl;
                return 0;
            }
            next = c.front();
            c.pop();
        }
    }
}
