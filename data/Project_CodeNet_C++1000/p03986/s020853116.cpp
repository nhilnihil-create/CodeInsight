#include <iostream>
#include <string>
using namespace std;
int main(){
    int s=0, st=0;
    string a;
    cin >> a;
    for(int i=0; i<a.size(); i++){
        if(a[i]=='S'){
            s++;
        }
        else{
            if(s>0){
                st++;
                s--;
            }
        }
    }
    st*=2;
    cout << a.size()-st << endl;
    return 0;
}