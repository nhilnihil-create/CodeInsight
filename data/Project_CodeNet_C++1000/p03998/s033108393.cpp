#include <iostream>
#include <queue>
using namespace std;

int main(){
    string A, B, C;
    cin >> A >> B >> C;
    queue<char>a, b, c;
    for(int i=0; i<A.size(); i++){
        a.push(A[i]);
    }
    for(int i=0; i<B.size(); i++){
        b.push(B[i]);
    }
    for(int i=0; i<C.size(); i++){
        c.push(C[i]);
    }
    char tmp;
    tmp = a.front();
    a.pop();
    while(true){
        if(tmp=='a'){
            if(a.size()==0){
                puts("A");
                return 0;
            } 
            tmp=a.front();
            a.pop();
        } else if(tmp=='b'){
            if(b.size()==0){
                puts("B");
                return 0;
            } 
            tmp=b.front();
            b.pop();
        } else {
            if(c.size()==0){
                puts("C");
                return 0;
            } 
            tmp=c.front();
            c.pop();
        }
    }


    return 0;
}