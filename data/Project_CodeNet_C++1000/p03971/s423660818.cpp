#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(void){
    int n,a,b;
    cin >> n >> a >> b;
    
    string s;
    cin >> s;
    
    int pass = 0;
    int overseas_pass = 1;
    
    for (int i = 0; i < n; i++){
        
        if (s[i] == 'a'){
            
            if (pass < a + b){
                cout << "Yes" << endl;
                pass++;
            }
            else{
                cout << "No" << endl;
            }
        }
        else if (s[i] == 'b'){
            
            if (pass < a + b && overseas_pass <= b){
                cout << "Yes" << endl;
                pass++;
                overseas_pass++;
                //cout << overseas_pass << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
