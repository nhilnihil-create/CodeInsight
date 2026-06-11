#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,A,B;
    cin >> N >> A >> B;
    string s;
    cin >> s;
    
    int passed=0;
    int a1 = 0;
    int b1 = 0;
    int passed2 = 0;
    for(int i = 0; i < N; i++){
        if(s[i] == 'a' && a1 == 0){
            if(passed < A+B){
                cout << "Yes"<<endl;
                passed += 1;
            }else{
                cout << "No"<<endl;
            }
        }
        
        if(s[i] == 'b' && b1 == 0){
            if(passed < A+B && passed2<B){
                cout << "Yes"<<endl;
                passed+= 1;
                passed2 += 1;
            }else{
                cout << "No" << endl;
            }
        }
        if(s[i] == 'c'){
            cout << "No" << endl;
        }
    }
    return 0;
}
