#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    string A, B;
    cin >> A;
    cin >> B;

    if(A.size() > B.size()){
        cout << "GREATER" << endl;
        return 0;
    }else if (A.size() < B.size()){
        cout << "LESS" << endl;
        return 0;
    }else{
        for(int i=0; i<A.size(); i++){
            int tmp_A = A[i] - '0';
            int tmp_B = B[i] - '0';
            if(tmp_A > tmp_B){
                cout << "GREATER" << endl;
                return 0;
            }else if(tmp_A < tmp_B){
                cout << "LESS" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
    }
    return 0;
}