#include <iostream>
using namespace std;
int main(void){
    string S;
    cin >> S;
    cout << S.at(0) << S.size()-2 << S.at(S.size()-1);
}
