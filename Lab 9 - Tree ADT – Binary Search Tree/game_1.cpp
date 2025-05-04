#include<iostream>

class game{
    public:
    int* el(int se,int pl[],int q);
};

int main(){
    game game;
    int test,k,q,se;
    printf("Enter the number of test case: ");
    scanf("%d",&test);
    int* result[test];
    int queries[test];
    for(int i=0;i<test;i++){
        printf("Enter the number of element in the sequence :");
        scanf("%d",&k);
        int seq[k];
        printf("Enter the value of q : ");
        scanf("%d",&q);
        int pl[q];
        
        printf("Enter the sequence:\n");
        for(int j=0;j<k;j++){
            scanf("%d",&seq[j]);
        }
        printf("Enter the q:\n");
        for(int j=0;j<q;j++){
            scanf("%d",&pl[j]);
        }
        se=seq[0];
        result[i]=game.el(se,pl,q);
    }
    printf("\nResults:\n");
    for (int i = 0; i < test; i++) {
        printf("Test Case %d: ", i + 1);
        for (int j = 0; j < queries[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int* game::el(int se,int pl[],int q){
    int*pans=new  int[q];
    for(int i=0;i<q;i++){
        if(pl[i]<se){
            pans[i]=pl[i];
        }
        else{
            pans[i]=(se-1);
        }
    }
    return pans;
}


