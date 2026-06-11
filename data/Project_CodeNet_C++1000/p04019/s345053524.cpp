#include <bits/stdc++.h>
using namespace std;

int main(void){
    string str;
    cin >> str;
    int n=0, s=0, e=0, w=0;
    for (int i=0; i<str.size(); i++){
        if (str[i] == 'S') s++;
        else if (str[i] == 'N') n++;
        else if (str[i] == 'E') e++;
        else w++;
    }
    if (s!=0 && n==0 || s==0 && n!=0 || e!=0 && w==0 || e==0 && w!=0){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}