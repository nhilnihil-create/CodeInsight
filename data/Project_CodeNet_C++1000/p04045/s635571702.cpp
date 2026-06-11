#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int max(int num, int size, int arr[]);
int isFound(int num ,int size, int arr[]);

int main(){
    string n , out;
    int  k , var = -8 , d[]={0,1,2,3,4,5,6,7,8,9};
    cin >> n;
    cin >> k;
    int dislike[k], like[10-k] , myarray[n.length()];
    
    for(int i=0; i<k;i++)
        cin>>dislike[i];
        
    sort(dislike, dislike+k); 
    set_difference(d,d+10,dislike,dislike+k ,like); 
    
    for(int i=0;i<n.length();i++){
        myarray[i] = n[i] - '0';
    }   
    
    for(int i=0 ; i<n.length();i++){
        if(isFound(myarray[i], 10-k,like) == 1){
            out += to_string(myarray[i]);
        }else if(max(myarray[i],10-k,like) != -1){
            out += to_string(max(myarray[i],10-k , like));
            var = i ;
            break;
        }else{
            if(i==0 && like[0]!=0){
                out = to_string(like[0]);
                var = -1 ;
                break;
            }else if(i==0 && like[0]==0){
                out = to_string(like[1]);
                var = -1 ;
                break;
            }else{
                myarray[i] = like[0] ;
                myarray[i-1] = myarray[i-1] + 1 ; 
                i-=2;
                if (!out.empty()) {
    		            out.pop_back();
    	        }
            }
        }
    }

    if(var != -8){
      for(int i=0 ;i<(n.length()-(1+var));i++){
        out += to_string(like[0]);
        }  
    }
    
    cout<< out ; 
    return 0;
}

int max(int num, int size, int like[]) {
    int result = -1;
    sort(like, like+size); 

 for(int i=0 ; i<size ; i++){
    if (like[i] > num){
        result = like[i];
        break;
    }
 }
    return result; 
}

int isFound(int num ,int size, int arr[]){
    int found = -1 ;
    for(int i=0; i<size ; i++){
        if(arr[i] == num){
            found = 1 ;
            break;
        }
    }
    return found ;
}




   