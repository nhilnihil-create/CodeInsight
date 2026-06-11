#include <iostream>

int main()
{
    long long a[7];
    for(int i=0; i<7; i++) scanf(" %lld", &a[i]);

    long long I = a[0];
    long long O = a[1];
    long long J = a[3];
    long long L = a[4];

    long long K = O + I + J + L;
    long long odd = I % 2 + J % 2 + L % 2;
    if(odd == 1 || odd == 2) K -= 1;
    if(odd == 2){
        if((I==1 && J==1) || (J==1 && L==1) || (L==1 && I==1)) K -= 1;
    }

    std::cout << K << std::endl;
}