#include<cstdio>

void(main){
    int i , j;
    int arr[] = { 3,6,7,1,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i = 0 ; i < (1<<n) ; i++){
        for(int j = 0 ; j <n ; j++){
            if(i &(1<<j)){
                printf("%d", arr[j]);
            }
        }
    }
}
