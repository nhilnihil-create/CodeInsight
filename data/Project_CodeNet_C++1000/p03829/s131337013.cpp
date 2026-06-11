#include<bits/stdc++.h>

int main()
{
    long long n,a,b;
    std::cin >> n >> a >> b;
    std::vector<long long> x(n);
    for(long long i = 0; i < n; i++)std::cin >> x[i];
    long long cur = x[0];
    long long res = 0;
    for(long long i = 0; i < n; i++){
        if((x[i] - cur) * a < b){
            res += (x[i] - cur) * a;
            cur = x[i];
        }else{
            cur = x[i];
            res += b;
        }
    }
    std::cout << res << std::endl;
}
