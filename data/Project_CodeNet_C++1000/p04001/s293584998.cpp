#include <iostream>
#include <bitset>
#include <string>
#include <cctype>
using namespace std;

long long manyFormula(string str){
    
    //int n = str.size();
    long long sum = 0;
    
    for(int i = 0; i < (1 << (str.size()-1) ); i++){
        
        bitset<10> bit(i);
        int savePosi = 0;
        int saveLength = 1;
        string num;
        
        for(int j = 0; j < (str.size()-1); j++){
            if(bit.test(j)){
                num = str.substr(savePosi, saveLength);
                //cout << "num = " << num << " savePosi = " << savePosi << " saveLength = " << saveLength << " i がある "<<endl;
                sum += stoll(num);
                saveLength = 1;
                savePosi = j + 1;
            }
            else saveLength++;
        }
        
        num = str.substr(savePosi, saveLength);
        sum += stoll(num);
        //cout << "num = " << num << " savePosi = " << savePosi << " saveLength = " << saveLength <<endl;
    }
    
    return sum;
}


int main(void){
    
    string S;
    cin >> S;
    
    long long ans = manyFormula(S);
    
    cout << ans << endl;
    
}
