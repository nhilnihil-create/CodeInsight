#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    string S;
    cin >> S;
    int count=0;
    int A=0;
    for(int i=0;i<N;i++){
       if(S.at(i)=='I'){
           A++;
       }
       else{
           A--;
       }
       count=max(count,A);
    }
    cout << count <<endl;
}