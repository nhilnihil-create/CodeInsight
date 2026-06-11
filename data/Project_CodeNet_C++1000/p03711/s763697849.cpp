#include <bits/stdc++.h>
using namespace std;

//1,...,12をグループ１
//4,...11をグループ9
//1+1 or 9+9 ならyes

int group(int a){
    if(a==1 || a==3 || a==5 || a==7 || a==8 ||a==10 || a==12) return 1;
    else if(a==4 || a==6 || a==9 || a==11) return 9;
    else return 0;
}
int main(){
    int x, y;
    cin >> x >> y;
    
    int a1 = group(x);
    int a2 = group(y);

    if(a1 + a2 == 2 || a1+a2 == 18) cout << "Yes" << endl;
    else cout << "No" << endl;
}