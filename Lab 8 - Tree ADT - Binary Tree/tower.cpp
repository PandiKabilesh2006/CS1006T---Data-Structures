#include <iostream>

class tree{
    private:
    int size;

    public:
    int work(int arr[],int tower);
};

int main(){
    tree tre;
    int testcase,tower;
    printf("Enter the number of test case :");
    scanf("%d",&testcase);
    int ans[testcase];
    for(int i=0;i<testcase;i++){
        printf("Enter the value of the tower :");
        scanf("%d",&tower);
        int arr[tower];
        printf("enter the blocks of the tower :");
        for(int j=0;j<tower;j++){
            scanf("%d",&arr[j]);
        }
        ans[i]=tre.work(arr,tower);

    }
    for(int i=0;i<testcase;i++){
        printf("%d ",ans[i]);
    }


    return 0;
}

int tree::work(int arr[],int tower){
    for(int i=1;i<tower;i++){
        while (true){
            if(arr[0]<arr[i]){
                arr[0]=arr[0]+1;
                arr[i]=arr[i]-1;
            }
            else{
                break;
            }
        }
    }
    return arr[0];
}