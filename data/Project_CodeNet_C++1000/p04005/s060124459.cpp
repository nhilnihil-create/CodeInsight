#include <iostream>
#include <algorithm>

using namespace std;

long long a[3];

int main() {
	
    for(int i = 0; i < 3; i++)
    {
    	cin >> a[i];
    }
    
    sort(a, a+3);
    
    long long a1 = a[2]/2;
    long long a2 = a[2] - a1;
    
    long long ans = abs(a1-a2);
    
    ans = ans * a[1] * a[0];
    
    cout<<ans<<endl;
    return 0;
}
