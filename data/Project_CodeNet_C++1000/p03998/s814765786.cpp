#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b,c;
    cin >> a >> b >> c;
    vector<int> x(3,0);
    int s = 0;
    while(1){

        //配列の大きさを越した場合はその人が勝利となる。
        if(x[0] > a.length()){
            cout << 'A' << endl;
            return 0;
        }else if(x[1] > b.length()){
            cout << 'B' << endl;
            return 0;
        }else if(x[2] > c.length()){
            cout << 'C' << endl;
            return 0;
        }

        //'a'を基準として、その数値となったら動作を行うようにする。
        if(s == 0){
            s = a[x[0]]- 'a';
            x[0]++;
        }else if(s == 1){
            s = b[x[1]] - 'a';
            x[1]++;
        }else{
            s = c[x[2]] - 'a';
            x[2]++;
        }

    }

    
}