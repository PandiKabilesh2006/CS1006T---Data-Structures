#include <cstdio>
#include <cstdlib>
#include <iostream>

int main(){
    int testcase,target_count,total_count,size,winner,count;
    printf("Enter the number of testcases:");
    scanf("%d",&testcase);
    for(int i=0;i<testcase;i++){
        printf("Enter the target count:");
        scanf("%d",&target_count);
        printf("Enter the total_count:");
        scanf("%d",&total_count);
        int target[target_count];
        int total[total_count];
        for(int i=0;i<target_count;i++){
            printf("Enter the target element %d:",i+1);
            scanf("%d",&target[i]);
        }
        for(int i=0;i<total_count;i++){
            printf("Enter the total element %d",i+1);
            scanf("%d",&total[i]);
        }

        for(int i=0;i<total_count;i++){
            winner=0;
            int array[target[target_count-1]];
            for(int j=0;j<total[i];j++){
                array[j]=j+1;
            }
            for(int j=0;j<target_count;j++){
                array[target[j]-1]=0;

            }
            for(int j=0;j<target[target_count-1];j++){
                if(array[j]!=0 && array[j]!=-1){
                    winner+=1;
                }
            }
            printf("%d",winner);
            
                
            
        }


    }
}