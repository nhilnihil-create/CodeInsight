#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i = 0; i < (int)(n); i++)

void cin_Ignore(){cin.ignore(numeric_limits<streamsize>::max(), '\n');}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    
    int X;
    cin >> X;
    
    for(int i = 1, count = 0;;i++){
        count += i;
        if (count >= X){
            cout << i; 
            return 0;
        }
    }
    
    
}

