#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,count=0,sum=0;
    cin >> n >> a >> b;
    char c;
    for(int i=0;i<n;i++){
        cin >> c;
        if(c == 'a'){
            if(count<a+b){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
            count++;
        }else if(c == 'b'){
            if(count<a+b&&sum<b){
                cout << "Yes" << endl;
                count++;
                sum++;
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}
