#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
int main() {
  // input
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i < n + 1; i++) cin >> a[i];

  // compute
    vector<int> b(n);
    int counter = 1;
    int f = 0;

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }    

    for(int i = 1; i < n; i++) b[i] = a[i + 1] - a[i];

    //flag
    if(b[1] > 0){
        f = 1;
    }else if(b[1] < 0){
        f = -1;
    }    

    for(int i = 1; i < n - 1 ; i++){
        if(f == 1){
            if(b[i + 1] >= 0){
            }else{
                counter++;
                f = 0;
            }
        }else if(f == -1){
            if(b[i + 1] <= 0){
            }else{
                counter++;
                f = 0;
            }            
        }else{
            if(b[i + 1] > 0){
                f = 1;
            }else if(b[i + 1] < 0){
                f = -1;
            }  
        }
        }

  // output  
    cout << counter << endl;

}
