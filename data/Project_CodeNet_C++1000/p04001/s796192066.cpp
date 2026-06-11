#include <iostream>
#include <bitset>
#include <string>
using namespace std;

long long manyFormula(string str){
    
    //int n = str.size();
    long long sum = 0;
    
    for(int i = 0; i < (1 << (str.size()-1) ); i++){
        
        bitset<10> bit(i);
        long long tmp = 0;
        
        for(int j = 0; j < str.size(); j++){
            tmp *= 10;
            tmp += str[j] - '0';
            if(bit.test(j)){
                sum += tmp;
                tmp = 0;
            }
        }
        sum += tmp;
    }
    
    return sum;
}


int main(void){
    
    string S;
    cin >> S;
    
    long long ans = manyFormula(S);
    
    cout << ans << endl;
    
}
