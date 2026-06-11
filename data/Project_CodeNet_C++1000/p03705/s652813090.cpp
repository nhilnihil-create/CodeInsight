#include <iostream>
using namespace std;
#define ll long long
int main(){
    ll n, a, b, sum=0, maxi=0, mini=0;
    cin >> n >> a >> b;
    if(a>b){
        cout << sum << endl;
    }
    else if(n==1){
        if(a!=b){
            cout << sum << endl;
        }
        else{
            sum =1;
            cout << sum << endl;
        }
    }
    else{
        maxi = a+b+(n-2)*b;
        mini = a+b+(n-2)*a;
        sum = maxi - mini + 1;
        cout << sum << endl;
    }
    return 0;
}