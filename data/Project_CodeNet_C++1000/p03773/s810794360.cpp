#include <bits/stdc++.h>
//#include <string.h>

using namespace std;

int main(){

    int A, B, counter;

    cin >> A >> B;

    counter = A;
    for(int i = 1; i <= B; i++){
        counter++;
        if(counter == 24){
            counter = 0;
        }
    }

    cout << counter << endl;

    return 0;

}