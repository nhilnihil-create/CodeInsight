#include<iostream>
#include<string>
using namespace std;
string S;
long long total = 0;
int scount[10] = {0};
long long temp = 0;


main(){

    cin >> S;

    for (int i = 0; i < S.length(); i++) scount[i] = S[i]-'0';

    int n = S.length();
    for (int bit = 0; bit < (1<<n-1); bit++){
        temp = scount[0];
        for (int i = 0; i < n-1; i++){
            if (bit & (1<<i)){
                total += temp;
                temp = scount[i+1];
            } else {
                temp = temp * 10 + scount[i+1];
            }
            
        }
        total += temp;
    }

    cout << total << endl;

    return 0;
}