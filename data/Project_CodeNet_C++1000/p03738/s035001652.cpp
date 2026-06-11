#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
 
using namespace std;

int main(){
    string A, B;    cin >> A >> B;
    int a = A.length(), b = B.length();
    if(a > b)   print("GREATER");
    else if(a < b)  print("LESS");
    else{
        for(int i=0; i<a; i++){
            if(A[i] > B[i]){print("GREATER");return 0;}
            else if(A[i] < B[i]){print("LESS");return 0;}
            else if(i == a-1)   print("EQUAL");
        }
    }
}