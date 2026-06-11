#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main() {
 
 int n,k,ct=0;
 cin>>n>>k;
 Vec vec(n);

 for(int i=0;i<n;i++){
    int x;
    cin>>x;
    int way=min(x,abs(k-x));
    ct+=2*way;
}
cout<<ct<<endl;
}