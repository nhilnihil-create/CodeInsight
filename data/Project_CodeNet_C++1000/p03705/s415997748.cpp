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
using namespace std;


int main(void){
    long N,A,B;
    cin >> N >> A >> B;
    if(N <= 1 && A != B)  cout << 0 << endl;
    else if(A > B) cout << 0 << endl;
    else cout << ((N-1)*B + A) - ((N-1)*A + B) + 1 << endl;
    return 0;
}   