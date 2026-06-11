#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n,a,b;
    cin >> n >> a >> b;
    
    string str;
    cin >> str;
    
    int pass = 0;
    int rank = 1;
    
    for(int i = 0;i < n;i++){
        char c = str[i];
        
        if(c == 'a'){
            if(pass < a + b){
                cout << "Yes" << endl;
                pass++;
            }else{
                cout << "No" << endl;
            }
        }
        
        if(c == 'b'){
            if(pass < a + b && rank <= b){
                cout << "Yes" << endl;
                pass++;
                rank++;
            }else{
                cout << "No" << endl;
            }
        }
        
        if(c == 'c'){
            cout << "No" << endl;
        }
    }
}
