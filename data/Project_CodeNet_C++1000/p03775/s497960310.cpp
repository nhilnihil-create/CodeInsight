#include <bits/stdc++.h>
// #include <math.h>
using namespace std;

int main(void)
{
    long long n;
    cin >> n;
    int a, b, res;
    int half = (int)std::sqrt(n);
    for(int i=half; i>=1; i--){
        if(n%i == 0){
            a = i;
            b = n/i;
            if (a<b){
                res = (int)std::log10(b);
            }
            else{
                res = (int)std::log10(a);
            }
            break;
        }
    }
    printf("%d\n", res+1);
}