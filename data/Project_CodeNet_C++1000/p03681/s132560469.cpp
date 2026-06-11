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
#include <boost/multiprecision/cpp_int.hpp>
#define DBL_MIN 0.000000000000001

#include <iostream>
using namespace std;


int main(void){
    long M,MM;
    long D,DD;
    cin >> M >> D;
    MM = M;
    DD = D;
    if(abs(M - D) > 1){
        cout << 0 << endl;
        return 0;
    }
    long m_pi = 1, d_pi = 1;
    for(M; M > 0 ;M-- ){
        m_pi *= M;
        m_pi = m_pi % 1000000007;
    }

    for(D; D > 0 ;D-- ){
        d_pi *= D;
        d_pi = d_pi % 1000000007;
    }
    if(MM == DD){
        cout << m_pi*d_pi*2 % 1000000007 << endl;
    }else{
        cout << m_pi*d_pi % 1000000007 << endl;
    }
}

