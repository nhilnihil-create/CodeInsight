#include <iostream>
#include <vector>

using namespace std;

long long int A, B, C;
long long int ans;

int main() {
    cin>>A>>B>>C;
    vector<long long int> p;
    p.push_back(A); p.push_back(B); p.push_back(C);
    sort(p.begin(), p.end());
    
    long long int mid_c1 = p[2] / 2;
    long long int mid_c2 = p[2] - mid_c1;
    
    if (mid_c1 > mid_c2) ans = mid_c1 - mid_c2;
    else ans = mid_c2 - mid_c1;
    
    ans = ans * p[1] * p[0];
    cout<<ans<<endl;
}
