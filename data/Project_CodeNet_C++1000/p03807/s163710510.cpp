#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin>>N;
    int even=0, odd=0;
    for(int i=0; i<N; i++) {
        int A;
        cin>>A;
        if(A%2==1) odd++;
    }
    cout<<((odd%2==0)?"YES":"NO")<<endl;

    return 0;
}