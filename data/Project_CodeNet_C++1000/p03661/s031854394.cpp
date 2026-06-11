#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#define INF 100000000
#define MOD 1000000007
using namespace std;


int main(){
    int N;
    cin >> N;
    
    long long sum=0;
    long long a[N];
    for(int i=0; i<N; i++){
        cin >> a[i];
        sum+=a[i];
    }
    
    long long m=abs(a[0]-(sum-a[0]));
    
    long long s=0;
    for(int i=0; i<N-1; i++){
        s+=a[i];
        m=min(m,abs(s-(sum-s)));
    }
    
    cout << m << endl;
    
    return 0;
}
