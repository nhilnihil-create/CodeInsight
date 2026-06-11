#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
#include<utility>
using namespace std;
 

int main(){
    int n, a, b;
    cin >> n >> a  >> b;
    string s;
    cin >> s;

    int counter = 0;
    int counter_f = 0;

    for(int i=0;i<s.size();i++){
        if(s[i] == 'a'){
            if(counter < a+b) {
                cout << "Yes" << endl;
                ++counter;
            }
            else cout << "No" << endl;
        }
        else if(s[i] == 'b'){
            ++counter_f;
            if(counter < a+b && counter_f <= b) {
                cout << "Yes" << endl;
                ++counter;
            }
            else cout << "No" << endl;
            
        }
        else{
            cout << "No" << endl;
        }
    }
}