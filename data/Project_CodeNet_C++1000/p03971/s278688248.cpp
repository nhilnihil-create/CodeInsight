#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;

    int passed = 0;
    int bpass = 0;
    for(int i=0; i<n; ++i){
        if(s[i]=='c'){
            cout << "No" << endl;
        }

        else if (s[i]=='a'){
            if(passed < a+b){
                cout << "Yes" << endl;
                passed++;
            }
            else
                cout << "No" << endl;
        }

        else{
            if(passed < a+b && bpass < b){
                cout << "Yes" << endl;
                passed++;
                bpass++;
            }
            else
                cout << "No" << endl;
        }
    }
    return 0;
}