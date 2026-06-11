#include<bits/stdc++.h>
using namespace std;
int main() {
    string o, e;
    cin >> o >> e;
    int i;
    int len1 = o.length();
    int len2 = e.length();
    int len = len1 + len2;
    int j, k;
    i = 0, j = 0;
    for(k=0; k<len; k++){
        if(i>=len1){
            cout << e[j];
            j++;
        }
        else if(j>=len2){
            cout << o[i];
            i++;
        }
        else if(k%2==0){
            cout << o[i];
            i++;
        }
        else{
            cout << e[j];
            j++;
        }
    }
    cout << endl;
    return 0;
}