#include<iostream>

class mass{
    public:
    void bi(int len,int arr[]);
};

int main(){
    mass mass;
    int test,len;
    printf("Enter the number of testcase :");
    scanf("%d",&test);
    for(int i=0;i<test;i++){
        printf("Enter the number of the elements in the array :");
        scanf("%d",&len);
        int arr[len];
        printf("Enter the elements in the array :");
        for(int j=0;j<len;j++){
            scanf("%d",&arr[j]);
        }
        mass.bi(len,arr);
    }
    return 0;
}

void mass::bi(int len,int arr[]){
    int max1,max2=0;
    int sol[len];
    max1=arr[0];
    for(int i=0;i<len;i++){
        if(max1<arr[i]){
            max2=max1;
            max1=arr[i];
        }
        else if (max2<arr[i]){
            max2=arr[i];
        }
    }
    for(int i=0;i<len;i++){
        if(arr[i]==max1){
            sol[i]=(max1-max2);
        }
        else{
            sol[i]=(arr[i]-max1);
        }
    }

    for(int i=0;i<len;i++){
        printf("%d ",sol[i]);
    }
    printf("\n");
}