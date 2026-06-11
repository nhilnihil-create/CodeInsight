#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;

    int avg=0;
    avg = (a+b+c)/2;

    if(avg == a+b || avg == a+c || avg == b+c){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}


