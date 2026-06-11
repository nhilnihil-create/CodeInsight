#include <bits/stdc++.h>
using namespace std;
int main(){
    long long q,h,s,d;
    cin >> q >> h >> s >> d;
    long long n;
    cin >> n;
    vector <long long> perDouble(4);
    perDouble[0] = q*4*2;
    perDouble[1] = h*2*2;
    perDouble[2] = s*1*2;
    perDouble[3] = d;
    long long price = perDouble[0];
    int bestPriceIndex = 0;
    for(int i = 1; i < 4; i++){
        if(price > perDouble[i]){
            price = perDouble[i];
            bestPriceIndex = i;
        } 
    }
    long long ans = 0;
    switch (bestPriceIndex)
    {
    case /* constant-expression */0:
        /* code */
        ans = n*q*4;
        break;
    case /* constant-expression */1:
        /* code */
        ans = n*h*2;
        break;
    case /* constant-expression */2:
        /* code */
        ans = n*s;
        break;
    case /* constant-expression */3:
        /* code */
        if(n%2==0){
            ans = n*d/2;
        }else{
            long long price = perDouble[0];
            int bestPriceIndex = 0;
            for(int i = 1; i < 3; i++){
                if(price > perDouble[i]){
                    price = perDouble[i];
                    bestPriceIndex = i;
                } 
            }
            if(n==1){
                switch (bestPriceIndex)
                {
                case /* constant-expression */0:
                    /* code */
                    ans = q*4;
                    break;
                case /* constant-expression */1:
                    /* code */
                    ans = h*2;
                    break;
                case /* constant-expression */2:
                    /* code */
                    ans = s;
                    break;
                default:
                    break;
                }
            }else{
                ans = (n-1)/2*d;
                switch (bestPriceIndex)
                {
                case /* constant-expression */0:
                    /* code */
                    ans += q*4;
                    break;
                case /* constant-expression */1:
                    /* code */
                    ans += h*2;
                    break;
                case /* constant-expression */2:
                    /* code */
                    ans += s;
                    break;
                default:
                    break;
                }
            }

        }
        break;
    default:
        break;
    }
    cout << ans << endl;
}