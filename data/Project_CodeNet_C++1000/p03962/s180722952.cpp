#include <iostream>
#include <map>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    map<int, int> mp;
    mp[a]++;
    mp[b]++;
    mp[c]++;
 
    cout << mp.size() << endl;
	return 0;
}