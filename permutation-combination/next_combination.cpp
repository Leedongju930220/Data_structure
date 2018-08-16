#include<iostream>  
#include<vector>  
#include<algorithm>  
using namespace std;  
  
int main(){  
      
    vector<int> num;  
  
    for(int i=0 ; i<3 ; i++){  
        num.push_back(i);  
    }  
  
    do{  
        for(int i=0 ; i<(int)num.size() ; i++) cout<<num[i]<<" ";  
        cout<<endl;  
    }while(next_permutation(num.begin(),num.end()));  
  
    return 0;  
}  

