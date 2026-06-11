#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
 
using namespace std;

int main() 
{
    int m;
    int n;
    int a[10], b;
 
    cin >> m;
    cin >> n;
 
    for (int i = 0; i < 10; i++){
        a[i] = 0;
    }
 
    for (int i = 0; i < n; i++){
        cin >> b;
        a[b]++;
    }
 
    for (int i = m; i < 100000; i++){
        b = i;
        while (b != 0){
            if (a[b % 10] != 0){
                break;
            }
            b /= 10;
        }
        if (b == 0){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}