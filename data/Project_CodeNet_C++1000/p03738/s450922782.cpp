#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main(void) {
    string A, B;
    cin >> A >> B;
    
    int i = 0;
    int flag = 0;
    
    if (A.length() > B.length()){
        cout << "GREATER" << endl;
        return 0;
    }
    else if(A.length() < B.length()){
        cout << "LESS" << endl;
        return 0;
    }
        
    while (flag && (A[i] == B [i])) {
        cout << A[i];
        i++;
    }
    
    if (A[i] > B[i])
        cout << "GREATER" << endl;
    else if(A[i] < B[i])
        cout << "LESS" << endl;
    else
        cout << "EQUAL" << endl;
    
    return 0;
}