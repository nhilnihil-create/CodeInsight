#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<string> vs;
    int H, W;
    cin >> H >> W;
    
    vs.resize(H);
    for(int i = 0; i < H; i++)
    {
        cin >> vs[i];
        cout << vs[i] << endl << vs[i] << endl;
    }
    
    
    return 0;
}
