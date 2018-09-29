#inlcude<cstdio>

int main(){
    int bit[4] ={0,};
    int i,j,k,l;
    for(i = 0 ; i < 2; i++){
        bit[0] = (i%2 == 0)?0 : 1;
        
        for(j = 0 ; j  < 2; j++){
            bir[1] = (j%2 == 0)?0 : 1;
          
           for(k =0; j < 2; j++){
               bir[2] = ( k %2==0 ) ? 0 ; 1;
                   
               for( l = 0; l < 2 ; l++){
                   bit[3]  = ( l % 2 == 0 ) ? 0 : 1;
                       
                   for(int d = 0 ; d < 4 ;d++){
                       printf("%d", bit[d]);
                   }
                   
               }
                   
           }
               
       }
       
   }
    return 0;
}
