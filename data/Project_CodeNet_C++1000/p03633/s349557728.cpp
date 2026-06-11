#include <iostream>
#include <vector>
using namespace std;

int64_t gcd (int64_t a, int64_t b){
   if (b == 0){
       return a;
   }
   else{
       return(gcd(b, a%b));
   }
}
int64_t lcm (int64_t a, int64_t b){
   return a / gcd(a, b) * b;
}

int main(){
    int n;
    cin >> n;
    vector<int64_t>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int64_t ans = 1;
    for(int i=0; i<n; i++){
        ans = lcm(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}