#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string stmp;
    
    cin >> stmp;
    
    int posA, posZ;
    posA = 300000;
    posZ = -300000;
    
    for(int i = 0; i < stmp.size(); i++)
    {
        if (stmp[i]=='A' && posA > i)
        {
            posA = i;
        }
        if (stmp[i]=='Z' && posZ < i)
        {
            posZ = i;
        }
    }
    cout << posZ - posA + 1 << endl;
    return 0;
}