#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main(){
    int n;
    list<int> a;
    int tmp_a;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp_a;
        if(i%2==0){
            a.push_back(tmp_a);
        }else{
            a.push_front(tmp_a);
        }
    }

    if(n%2!=0){
        reverse(a.begin(), a.end());
    }

    for(auto itr=a.begin(); itr!=a.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}
