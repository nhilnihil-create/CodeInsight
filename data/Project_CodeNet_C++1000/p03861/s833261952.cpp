// B Between a and b
#include <bits/stdc++.h>
using namespace std;

// overflow....

int not_good_main(){
    long a,b,x; // 0 < a<= b, 0<x  10^18
    cin >> a >> b >> x;
    long num = b- a +1;
    long div = num / x;
    long res = num % x;
    long count = div;
    for (long i = 0; i < res ; i ++){
        if ((i + a) % x == 0)
            count ++;
    }
    
    cout << count << endl;
}

long func(long n, long x){
    if (n >= 0){
        return  n/x + 1;
    }
    else{
        return 0;
    }
}

int main(){
    long a,b,x; // 0 < a<= b, 0<x  10^18
    cin >> a >> b >> x;
    long count = func(b, x) - func(a-1,x);
    cout << count << endl;
}