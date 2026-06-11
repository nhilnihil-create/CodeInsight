#include <iostream>
#include <string>
using namespace std;
string Sa,Sb,Sc;
int a_cnt = 0;
int b_cnt = 0;
int c_cnt = 0;
string ans = "A";

void make_turn(char id){
    if(id == 'a'){
    	if(a_cnt < Sa.size()){
    	    a_cnt++;
    	    make_turn(Sa[a_cnt-1]);
    		}
    	else{
    	    ans = "A";
    		}
    	}
    else if(id == 'b' ){
    	if(b_cnt < Sb.size()){
    	    b_cnt++;
    	    make_turn(Sb[b_cnt-1]);
    	    }
    	else{
    	    ans = "B";
    		}
    	    
    	}
    else if(id == 'c'){
    	if(c_cnt < Sc.size()){
    	    c_cnt++;
        	make_turn(Sc[c_cnt-1]);
         }
    	else{
    	    ans = "C";
    		}	
    	}
	}

int main(){
	
	cin >> Sa >> Sb >> Sc;
	
	make_turn('a');
	
	cout << ans << endl;
		
		
	return 0;
	}
