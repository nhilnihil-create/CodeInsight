#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<numeric>
#include<iomanip>
#include<utility>
#include<cstdlib>
#include<typeinfo>
#include<stack>
#include<cassert>
#include<functional>
#define int long long int
#define double long double
using namespace std;
#define INT_MAX 1000000007
#define INF 1000000000000000007
const int MAX_N = 1 << 17;
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

signed main()
{
int n;
std::cin >> n;
std::vector<int> a;
int onef = 0;
int sum = 0;
int turn = 1;
for(int i = 0; i < n; i++){
    int temp;
    std::cin >> temp;
    a.push_back(temp);
    sum += temp - 1;
    if(temp == 1){
        onef = 1;
    }
}
int flag = 0;

if(onef){
    flag = (sum%2 == 0)? -1:1;
}else {
while(flag == 0){
    int tempsum = 0;
    int temp = 0;
    int ecounter = 0;
    int ocounter = 0;
    int odd = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            onef = 1;
        }
        tempsum += a[i] - 1;
        if(a[i] % 2 == 0){
            ecounter++;
        } else {
            ocounter++;
            odd = i;
        }
    }
    if(onef){
        flag = (tempsum%2 == 0)? -1*turn:1*turn;
        break;
    }
    if(ecounter % 2 == 1){
        flag = 1*turn;
        break;
    } else {
        if(ocounter >= 2){
            flag = -1*turn;
            break;
        } else {
            int g = a[0];
            a[odd]--;
            for(int i = 1; i < n; i++){
                g = gcd(g,a[i]);
            }
            for(int i = 0; i < n; i++){
                a[i] = a[i]/g;
            }
            turn *= -1;
        }
    }
}
}

if(flag == 1){
    std::cout << "First" << std::endl;
} else {
    std::cout << "Second" << std::endl;
}

return 0;
}