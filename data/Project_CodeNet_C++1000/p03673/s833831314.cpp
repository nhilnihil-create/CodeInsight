#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i;
    cin >> n;

    vector<int>  a(n+1);
    for(i=1; i<=n; i++){
        cin >> a.at(i);
    }


    if(n % 2 == 0  && n > 2){
        for(i=n; i>=2; i-=2){
            cout << a.at(i) << " ";
        }
        for(i=1; i<n-1; i+=2){
            cout << a.at(i) << " ";
        }
        cout << a.at(n-1) << endl;
    }else if(n % 2 == 1 && n > 1){
        for(i=n; i>=1; i-=2){
            cout << a.at(i) << " ";
        }
        for(i=2; i<n-1; i+=2){
            cout << a.at(i) << " ";
        }
        cout << a.at(n-1) << endl;
    }



    if(n == 1){
        cout << a.at(1) << endl;
    }

    if(n == 2){
        cout << a.at(2) << " " <<a.at(1) << endl;
    }


    return 0;
}