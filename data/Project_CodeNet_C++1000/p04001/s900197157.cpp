#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <iterator>
#include <algorithm>
#include <cfenv>
#include <random>
#include <numeric>
#include <cmath>
#include <iosfwd>
#include <iostream>
#include <ios>
#include <streambuf>
#include <istream>
#include <ostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include<string>

#define SIZE 100002
typedef long long ll;
 
using namespace std;

int main(){
    string S;
    cin >> S;
    int n=(int)S.size();
    ll sum=0;
    for(int bit = 0 ; bit < (1<<n-1) ; bit++){
        ll sum_tmp = 0;
        for(int i = 0 ; i < n-1 ; i++){
            sum_tmp = sum_tmp*10 + (S[i] - '0');
            if(bit & (1<<i)){
                sum += sum_tmp;
                sum_tmp = 0;
            }
        }
        sum += sum_tmp*10 + (S[n-1] - '0');
    }
    cout << sum;
}