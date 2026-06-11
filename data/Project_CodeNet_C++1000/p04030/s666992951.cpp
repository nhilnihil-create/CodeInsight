#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std ;

int main(){
    std::ios_base::sync_with_stdio(0);  cin.tie(NULL);  cout.tie(NULL);
    string text , actions ;
    cin >> actions ;
    for(int i = 0 ; i < actions.size() ; i++){
        if(actions[i] == '1') text += '1' ;
        else if(actions[i] == '0') text += '0' ;
        else {
            if(text.size() > 0)
            text.pop_back() ;
        }
    }
    cout << text ;
    return 0 ;
}