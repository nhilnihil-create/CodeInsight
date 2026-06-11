#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
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
#include <math.h> // sqrt()

using namespace std;

int main(){
    int n, a;
    cin >> n;
    vector<int> yolo;
    vector<int> bruh;
    cin >> a;
    yolo.push_back(a);
    for (int i = 1; i < n; i++){
        if (i % 2 == 1){
            cin >> a;
            yolo.push_back(a);
        }
        else{
            cin >> a;
            bruh.push_back(a);
        }
        
    }
    if (n % 2 ==0){
    reverse(yolo.begin(), yolo.end());
    for (int i : yolo)
        cout << i << ' ';
    for (int i : bruh)
        cout << i << ' ';


    
    }
    else {
        reverse(bruh.begin(), bruh.end());
        for (int i : bruh)
            cout << i << ' ';
        for (int i : yolo)
            cout << i << ' ';
        
    }
    cout << endl;

}
