#include <iostream>
using namespace std;
 
int main() {
	string line;
    cin >> line;
    for (int i=0; i<5; i++){
    	cout << line[i];
    }
    cout << ' ';
    for (int i=6; i<13; i++){
    	cout << line[i];
    }
    cout << ' ';
    for (int i=14; i<line.length(); i++){
    	cout << line[i];
    }
    cout << endl;
}