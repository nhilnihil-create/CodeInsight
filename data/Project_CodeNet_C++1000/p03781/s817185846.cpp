#include <iostream>
using namespace std;
int main(void){
    int x, ng = 0, ok = 1e9;
    cin >> x;
    while(ng + 1 < ok){
        long long mid = (ng + ok) / 2;
        if(mid*(mid+1)/2 >= x)ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}
