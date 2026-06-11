#include<iostream>
using namespace std; 
int main(){
    string x;
    int y = 0;
    string z = "CODEFESTIVAL2016";
    for (int i = 0; i <= 15; i++)
    	{
    		cin >> x[i];
			if	(x[i] != z[i])
				{
					y++;
				}
		}
	cout << y << endl;
    return 0;
}