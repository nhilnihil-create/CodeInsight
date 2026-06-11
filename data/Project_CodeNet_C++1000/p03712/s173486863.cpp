#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int h,w;
    cin >> h>>w;
    vector<vector<char>> vec(h+2,vector<char>(w+2,'#'));
    
  	for(int i=1 ;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>vec.at(i).at(j);
        
        }
     	cout<<" \n";
    }
    
    for(int i=0 ;i<h+2;i++){
        for(int j=0;j<w+2;j++){
            cout<<vec.at(i).at(j);
        
        }
     	cout<<" \n";
    }
    
    return 0;
}
