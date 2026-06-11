#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n; cin >> n;
    string s; cin >> s;
    
    int left_num = 0;
    int right_num = 0;
    int curr = 0;
    
    
    for (int i=0; i<n; i++){
        if(s[i] == '('){
            curr++;
        }else if(curr > 0){
            curr--;
        }else{
            left_num++;
        }
    }
    right_num = curr;
    
    for (int i=0; i<left_num; i++) {
        cout << "(";
    }
    cout << s;
    for (int i=0; i<right_num; i++) {
        cout << ")";
    }
    cout << endl;
}
