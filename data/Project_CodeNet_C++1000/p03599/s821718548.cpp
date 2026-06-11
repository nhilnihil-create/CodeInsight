#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;
 
int main(){
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    double x = 0;
    int water = 100*A, suger = 0;
    
    for(int i = 0; i <= F; i += 100*A){
        for(int j = i; j <= F; j += 100*B){
            if(j == 0) continue;
            else{
                for(int k = j; k <= F; k += C){
                    for(int l = k; l <= F; l += D){
                        if(l-j <= E*j/100){
                            if(x < double(l-j)/double(l)){
                                x = double(l-j)/double(l);
                                water = l;
                                suger = l-j;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << water << ' ' << suger << endl;
}