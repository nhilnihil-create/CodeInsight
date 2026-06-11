#include <bits/stdc++.h>

using namespace std;


int main(){

    long long a, b, c; cin >> a >> b >> c;

     long long add = a%b;

    if(add == 0){
         if(add == c)
         cout<<"YES"<<endl;
         else cout<<"NO"<<endl;

        return 0;
    }

    for(long long i=add; i<=10000; i+=add)
    {
        if(i%b == c%b){
            cout<<"YES";
          return 0; }
    }


    cout<<"NO"<<endl;

    return 0;
}
