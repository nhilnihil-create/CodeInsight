#include <iostream>
using namespace std;
 
int main()
{
	string s;
    cin >> s;
    int t = s.size();
    while(t > 1){
        t -= 2;
        if(s.substr(0, t/2) == s.substr(t/2, t/2)) break;
    }
    cout << t << endl;


	return 0;
}