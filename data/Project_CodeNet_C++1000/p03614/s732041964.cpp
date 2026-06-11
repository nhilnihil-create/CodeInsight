#include <iostream>

using namespace std;

int main()
{
    int n , rez(0);
    cin >> n;
    int a;
    int p = 0;
    for(int i = 1; i<= n ; i++){
        cin >> a;
        if(a == i){
            if(p == 0){
                rez++;
                p = 1;
            }else{
                p = 0;
            }
        }else{
        p = 0;
        }
    }
    cout << rez;
}
