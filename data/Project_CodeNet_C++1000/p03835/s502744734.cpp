#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <regex>
#include <initializer_list>
#include <deque> 
#define DBL_MIN 0.000000000000001

#include <iostream>
using namespace std;


int main(void){
    long K,S;
    cin >> K >> S;

    int cnt = 0;
    for(int i =0; i <= K ;i++){
        for(int j = 0; j <=  (S- i) && j <= K ; j++){
            if( (S-i-j) <= K){
                //cout << i << ":" << j << ":" << (S-i-j) << endl;
                cnt++;
            }
        }   
    }
    cout << cnt << endl;
    return 0;
}

