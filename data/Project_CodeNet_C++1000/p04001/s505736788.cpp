#include<iostream>
#include<cmath>
using namespace std;

int main(){

    long long sum = 0;
    string S;
    cin >> S;

    int n = S.size(); 
    for (int i = 0; i < pow(2, n-1);i++){
        long long  part = 0;
        for(int j = 0; j < n-1;j++){

            part *= 10;
            part += (int)(S[j] - '0');
            if((i & (int)pow(2, j)) != 0){
                sum += part;
                part = 0;
            }
        }
        part *= 10;
        part += (int)(S[n-1] - '0');
        sum += part;

    }

    cout << sum << endl;
}