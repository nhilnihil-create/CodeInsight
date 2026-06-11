#include <bits/stdc++.h>
using namespace std;

    int tmp1,tmp2;

int main(){
    int A,B,C;
    long long int count=0;
    cin >> A >> B >> C;
    if(A==B && A==C){
        if(A%2) count=0;
        else count=-1;
    }
    else{
        while(1){
        if(A%2 || B%2 || C%2) break;
        count++;
        tmp1=A; 
        tmp2=B;
        A=B/2+C/2;
        B=tmp1/2+C/2;
        C=tmp1/2+tmp2/2;
        }
    }
    cout << count << endl;
}