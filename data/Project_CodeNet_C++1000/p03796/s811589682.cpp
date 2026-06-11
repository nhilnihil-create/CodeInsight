#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main() {
       long long n,z=1;
       cin>>n;
       for(int i=1;i<=n;i++){
              z*=i;
              z%=1000000007;


       }

	cout<<z;
    return 0;
    }


