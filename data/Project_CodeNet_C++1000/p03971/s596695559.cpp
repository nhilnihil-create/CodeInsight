#include <iostream>
using namespace std;
int main(void){
    
    int N,A,B,now=0,c_b = 0;
    string S;
    cin >> N >> A >> B >> S;
    
    int len = S.size();
    for(int i=0;i<len;i++){
        
        if(S.at(i) == 'a'){
            if(now < A + B){
                now++;
                cout << "Yes" << endl;
            }
            else{
                cout << "No" <<endl;
            }
        }
        else if(S.at(i) == 'b'){
            c_b++;
            if(now < A + B && c_b <= B){
                now++;
                cout << "Yes" << endl;
            }
            else{
                cout << "No" <<endl;
            }
        }
        else{
            cout << "No" <<endl;
        }
    }
    return 0;
}