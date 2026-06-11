#include <bits/stdc++.h>
using namespace std;

int ctoi(char c){
    if (c>='0' && c<='9'){
        return c-'0';
    }
    return 0;
}
int main(){
    string A, B;
    cin >> A >> B;
    if (A.length()>B.length()) {
        cout << "GREATER" << endl;
        return 0;
    }
    else if(A.length() < B.length()){
        cout << "LESS" <<endl;
        return 0;
    }
    else {
        for (int i=0; i<A.length(); i++){
            if (A.at(i)!=B.at(i)){
                int a=ctoi(A.at(i));
                int b=ctoi(B.at(i));
                if (a>b) {
                    cout << "GREATER" << endl;
                    return 0;
                }
                else {
                    cout << "LESS" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "EQUAL" << endl;
}