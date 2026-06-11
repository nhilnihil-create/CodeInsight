#include <iostream>
using namespace std;

int main()
{
    char S[17];
    int counter = 0;
    cin >> S;
    char ac[17] = "CODEFESTIVAL2016";
    for(int i = 0; i < 16; i++){
        if(S[i] != ac[i]){
            ++counter;
        }
    }
    cout << counter << endl;
    

    return 0;
}
