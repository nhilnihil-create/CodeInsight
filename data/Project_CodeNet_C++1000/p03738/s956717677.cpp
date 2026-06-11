#include <iostream>
#include <string>
using namespace std;
int main(void){
    string A,B;
    cin >> A >> B;
    if(A.size() != B.size()){
        if(A.size() > B.size()){
            cout << "GREATER" << endl;
        }
        else{
            cout << "LESS" << endl;
        }
        return 0;
    }
    for(int i=0;i<A.size();i++){
        if(A[i] > B[i]){
            cout << "GREATER" << endl;
            return 0;
        }
        if(A[i] < B[i]){
            cout << "LESS" << endl;
            return 0;
        }
    }
    cout << "EQUAL" << endl;
}
