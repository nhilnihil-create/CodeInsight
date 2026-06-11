#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long int LLI;

int main()
{
    int n;
    cin >> n;
    if( n/100 == n%10 )
    	cout << "Yes";
    else cout << "No";
}