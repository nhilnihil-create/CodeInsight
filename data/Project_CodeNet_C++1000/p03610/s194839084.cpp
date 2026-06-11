#include <iostream>
using namespace std;

string N,out_moji;
double x,H[1100],T,A;        

int main() {
    cin >> N;
    x = N.size();

        for (int i = 0; i < x; i = i +2) {
        
           out_moji = out_moji + N[i];
        
        }

    // cout << max << endl;
   //  cout << min << endl;
   // max = max - min;
    cout << out_moji << endl;
}