#include<iostream>
#include<list>
#include<set>
#include<string>
#include<cmath>

using namespace std;

int main(){
  	string s;
    cin >> s;
    
	int size = s.size();
  	bool conditionEven = size % 2 == 0;
    bool conditionStartMatchToEnd = s[0] == s[size-1];
    bool conditionWinner = conditionEven ^ conditionStartMatchToEnd;
    
  	string winner;
    if (conditionWinner){
      winner = "Second";
    }
  	else{
      winner = "First";
    }
  
    cout << winner << endl;
}
