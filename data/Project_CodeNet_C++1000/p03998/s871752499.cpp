#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    string A,B,C;
    char win;
    cin >> A >> B >> C;
    int maisu_a=A.size(),maisu_b=B.size(),maisu_c=C.size();
    int a_now=0,b_now=0,c_now=0;
    char turn = A[0];
    while(1){
        if(turn == 'a'){
            a_now++;
            if(a_now == maisu_a+1){
                win = 'A';
                break;
            }
            turn = A[a_now-1];
        }
        else if(turn == 'b'){
            b_now++;
            if(b_now == maisu_b+1){
                win = 'B';
                break;
            }
            turn = B[b_now-1];
    }
     else if(turn == 'c'){
            c_now++;
            if(c_now == maisu_c+1){
                win = 'C';
                break;
            }
            turn = C[c_now-1];
    }
}
if(win == 'A') cout << 'A'<<endl;
else if(win == 'B')cout << 'B' <<endl;
else if(win == 'C')cout << 'C' <<endl;
}