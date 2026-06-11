#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    //freopen("../input.txt","r",stdin);
    ll a, b, x;
    cin >> a >> b >> x;

    ll one_to_a_all_divisible = a/x;
    ll one_to_b_all_divisible = b/x;

    if(a%x == 0){
        one_to_a_all_divisible = one_to_a_all_divisible - 1;
    }

    cout << one_to_b_all_divisible - one_to_a_all_divisible;
}