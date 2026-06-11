#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    for(int i=1;i<S.size()+1;i++){
        if(i%2==1){
            cout << S.at(i-1);
        }
    }
}