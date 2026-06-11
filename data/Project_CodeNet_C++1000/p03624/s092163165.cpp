#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    char A[30]={0};
    for (char c='a'; c<='z'; c++){
        bool found=false;
        for (int i=0; i<S.length(); i++){
            if (S.at(i)==c) found=true;
        }
        if (!found){
            cout << c << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}