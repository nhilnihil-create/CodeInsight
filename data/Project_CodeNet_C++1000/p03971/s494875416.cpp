#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,a,b;
    int count = 0;
    int countB = 1;
    string s;
    cin >> n >> a >> b >> s;

    for(int i = 0; i < n; i ++){
        if(s[i] != 'c'){
            if(count < a+b){
                if(s[i] == 'a'){
                    count ++;
                    cout << "Yes" << endl;
                }else if(s[i] == 'b' && countB <= b){
                    count ++;
                    countB ++;
                    cout << "Yes" << endl;
                }else{
                    cout << "No" << endl;
                }
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}