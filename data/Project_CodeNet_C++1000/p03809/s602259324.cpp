#include<bits/stdc++.h>

using namespace std;

int init = 0;

bool sl = true;
vector<vector<int> > tree;
vector<long long> pesos;

vector<int> visto;
long long sol(int ver){

	visto[ver] = 1;

	long long count = 0;
	long long val = 0;
	vector<long long> vecVal;
	for(int i = 0; i < tree[ver].size(); i++){
		if(visto[tree[ver][i]] == 0){
			count++;
			long long v = sol(tree[ver][i]);
			vecVal.push_back(v);
			val += v;
		}
	}

	if(count == 1){

            if(val != pesos[ver]){
                     sl = false;
                     return 0;
            }else{
                  return val;
            }
     }else if(ver == init){


 		if(2*pesos[ver]-val != 0){
 		                   sl = false;
 		                   return 0;
 		           }else{
 		        	   int acomu = val;

 		        	   sort(vecVal.begin(), vecVal.end());
 						for(int i = vecVal.size()-1; i >= 0; i--){
 						//	cout << vecVal[i] << '\n';
 							if(vecVal[i] == val - pesos[ver]){
 								return 2*pesos[ver]-val;
 							}else if(vecVal[i] < val - pesos[ver] && acomu >= val - pesos[ver]){
 								return 2*pesos[ver]-val;
 							}else if(vecVal[i] > val - pesos[ver] && val - vecVal[i] >= val - pesos[ver]){
 								return 2*pesos[ver]-val;
 							}
 							acomu -= vecVal[i];
 						}
 		        	   	 sl = false;
 		        	   	 return 0;

 		           }
 	}else if(count == 0){
           return pesos[ver];
     }else{

           if(2*pesos[ver]-val < 0 || pesos[ver] > val){
                   sl = false;
                   return 0;
           }else{

	        	   if(val - pesos[ver] == 0) return 2*pesos[ver] - val;
	        	   sort(vecVal.begin(), vecVal.end());
		        	   int acomu = val;
		        	  // sort(vecVal.begin(), vecVal.end());
						for(int i = vecVal.size()-1; i >= 0; i--){

							if(vecVal[i] == val - pesos[ver]){
								return 2*pesos[ver]-val;
							}else if(vecVal[i] < val - pesos[ver] && acomu >= val - pesos[ver]){
								return 2*pesos[ver]-val;
							}else if(vecVal[i] > val - pesos[ver] && val - vecVal[i] >= val - pesos[ver]){
								return 2*pesos[ver]-val;
							}
							acomu -= vecVal[i];
						}
		        	   	 sl = false;
		        	   	 return 0;
           }
     }
}





int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
         vector<int> aux;
         tree.push_back(aux);
         long long auxa;
         cin >> auxa;
         pesos.push_back(auxa);
         visto.push_back(0);
    }

    for(int i = 0; i < n-1; i++){
            int a,b;
            cin >> a >> b;
            tree[a-1].push_back(b-1);
            tree[b-1].push_back(a-1);
    }
    init = 0;
    for(int i = 0; i < n; i++){
    	if(tree[i].size() != 1){
    		init = i;
    		break;
    	}
    }



    sol(init);

    if(sl) cout << "YES";
    else cout << "NO";
}