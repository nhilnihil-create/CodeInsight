#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string S;
    cin >> S;
    int n = S.size();
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(S[i]==S[j])count++;
            if(count==1)goto RESULT;
        }
    }

RESULT:
    if(count==1)cout << "no";
    else cout <<"yes";
}
