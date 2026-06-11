#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() { 
    ll N, A, B;
    string S;
    cin >> N >> A >> B >> S;

    ll kokunai=0, kaigai=0;
    for(int i=1; i<=N; i++){
        char c = S[i-1];
        if(c=='a'){
            if(kokunai+kaigai<A+B){
                kokunai++;
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else if(c=='b'){
            if(kokunai+kaigai<A+B && kaigai < B){
                kaigai++;
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else{
            cout << "No" << endl;
        }
    }
}