#include <iostream>
using namespace std;
 
int main(){
    int X, A, B;
    cin >> X >> A >> B;
    if ( (X-A)*(X-A) > (X-B)*(X-B) )
	{
        cout << "B" ;
    }
    else
	{
        cout << "A" ;
    }
}