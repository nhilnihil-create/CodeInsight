#include <bits/stdc++.h>
using namespace std;

int main(){

    long long int n,a,b;
    cin >> n >> a >> b;

    long long min_num,max_num;
    min_num=a*(n-1)+b;
    max_num=a+b*(n-1);

    if(min_num>max_num) cout << 0 << endl;
    else cout << max_num-min_num+1 << endl;
}