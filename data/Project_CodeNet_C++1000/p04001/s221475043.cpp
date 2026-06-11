#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int pow(int b, int k){
    int r = 1;
    for(int i=0 ; i<k ; i++){
        r *= b;
    }
    return r;
}

int main() {
    string formula;
    unsigned long int sum = 0;
    cin >> formula;

    for(int i=0 ; i<pow(2, formula.size()-1) ; i++){
        unsigned long int sum_part = formula.at(0) - 48;
        for(int j=0 ; j<formula.size()-1 ; j++){
            bool flag;
            if((i>>j)%2==1){flag=true;}else{flag=false;}
            if(flag){
                sum += sum_part;
                sum_part = formula.at(j+1) - 48;}
            else{sum_part = 10*sum_part + formula.at(j+1) - 48;}
        }
        sum += sum_part;
    }

    cout << sum <<endl;

}
