#include <bits/stdc++.h>
using namespace std;

int ctn(int a, int b, int c){
    if(a%2==1 || b%2==1 || c%2==1) return 0;
    else return 1;
}

int main(){
    int A,B,C; cin >> A >> B >> C;
    int count = 0;
    
    while(ctn(A,B,C)){
        if(A==B&&B==C) {count = -1; break;}
        count += 1;
        int a=A; int b=B; int c=C;
        A = (b+c)/2; B=(a+c)/2; C=(a+b)/2;
    }
    cout << count << endl;
}