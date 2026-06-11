#include <iostream>
//#include <vector>
//#include <string>
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

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 200100
//#define NIL -1

int main() {
    int n;
    LL a;
    int odd_num=0;
    int x2_num=0;
    int x4_num=0;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        if(a%2!=0){
            odd_num++;
        }else if(a%4==0){
            x4_num++;
        }else{
            x2_num++;
        }
    }

    bool ok;
    if(x4_num>=odd_num){
        ok=true;
    }else if(x4_num+1==odd_num && x2_num%2==0){
        ok=true;
    }else{
        ok=false;
    }

    if(ok==true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
