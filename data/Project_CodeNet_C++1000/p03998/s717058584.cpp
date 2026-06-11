#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <cstring>
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <numeric>
#include <float.h>
#include <math.h>
#include <sstream>
using namespace std;
// repマクロの定義
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// allマクロの定義
#define all(v) v.begin(), v.end()

typedef unsigned long long ll;

int ctoi(char c) {
 	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

int main(){ 
string a,b,c;
cin >> a >> b >> c;
queue<char> Sa;
queue<char> Sb;
queue<char> Sc;
rep(i,a.size()){
    Sa.push(a[i]);
}
rep(i,b.size()){
    Sb.push(b[i]);
}
rep(i,c.size()){
    Sc.push(c[i]);
}
char x; x = Sa.front();
Sa.pop();
while(true){
    if(x == 'a'){
        if(Sa.empty()){ 
            cout << 'A' << endl;
            return 0;
        }
        x = Sa.front();
        Sa.pop();  
          }  
    else if(x == 'b'){
        if(Sb.empty()){ 
            cout << 'B' << endl;
            return 0;
        }        
        x = Sb.front();
        Sb.pop();
    } 
    else {
        if(Sc.empty()){ 
            cout << 'C' << endl;
            return 0;
        }        
        x = Sc.front();
        Sc.pop(); 
    }
}

}



