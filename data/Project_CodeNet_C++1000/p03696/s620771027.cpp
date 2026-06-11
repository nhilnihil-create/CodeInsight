#include <iostream>
//#include <vector>
#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main() {
    int n;
    string s;
    int num_front=0;
    int num_back=0;

    cin >> n;
    cin >> s;
    for(int i=0; i<n; i++){
        if(s[i]=='('){
            num_front++;
        }
        if(s[i]==')'){
            if(num_front!=0){
                num_front--;
            }else{
                num_back++;
            }
        }
    }

    for(int i=0; i<num_back; i++){
        cout << '(';
    }
    cout << s;

    for(int i=0; i<num_front; i++){
        cout << ')';
    }
    cout << endl;
 
    return 0;
}