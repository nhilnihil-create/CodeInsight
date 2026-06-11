#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string x;
    cin >> x;
    
    int stack = 0;
    int p=0;
    for (int i=0; i<x.size(); i++){
        if(x[i] == 'S'){
            stack++;
        }else if(stack > 0){
            stack--;
            p++;
        }
    }
    cout << x.size() - p * 2 << endl;
}
