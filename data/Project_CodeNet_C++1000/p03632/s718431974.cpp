#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;

int main(){

    int A,B,C,D;
    cin >> A >> B >> C >> D;
    int t=0;
    int first,last;

    last = B<D ? B : D;

    first = A<C ? C : A;

    t = last - first;
    if(t<0)
    {
        std::cout << "0";
    }else{
        std::cout << t;
    }

    return 0;
}


