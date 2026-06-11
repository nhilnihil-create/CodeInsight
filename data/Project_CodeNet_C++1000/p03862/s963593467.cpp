#include<iostream>
#include<math.h>

using namespace std;

int main(){
    long N, x, a, b, n=0;
    cin >> N >> x >> a;
    for (long i=1; i<N; i++){
        cin >> b;
        if (a + b > x ){
            n += a + b - x;
            if (x - a >= 0){
                b = x - a;
            }else{
                b = 0;
            }
        }
        a = b;
        //cout << n << endl;
    }

    cout << n << endl;
    return 0;
}