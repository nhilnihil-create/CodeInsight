#include <iostream>
#include<algorithm>
using namespace std;


int main() {

    int n, d;
    cin>>n;
    d=2*n;

    int a[d], count=0;

    for(int i=0; i<d; i++) cin>>a[i];


    sort(a, a+d);

    for(int i=0; i<d; i+=2){
        count+=a[i];
    }

    cout<<count<<endl;

}
