#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#define MAX_VERTICES 100
using namespace std;

class Graph{
    private:
    int numvertices;
    int AdjMatrix[MAX_VERTICES][MAX_VERTICES];

    public:
    Graph(int vertices);
    void insertEdge(int a,int b);
    void deleteEdge(int a,int b);
    void searchEdge(int a,int b);
    void display();

};

Graph::Graph(int vertices){
    if(vertices>MAX_VERTICES){
        numvertices=MAX_VERTICES;
    }
    else{
        numvertices=vertices;
    }

    for(int i=0;i<numvertices;i++){
        for(int j=0;j<numvertices;j++){
            AdjMatrix[i][j]=0;
        }
    }


}

void Graph::insertEdge(int a,int b){
    if(a>numvertices || b>numvertices || a<0 || b<0){
        cout<<"Invalid vertices\n";
        return;
    }
    AdjMatrix[a][b]=1;
    AdjMatrix[b][a]=1;
    cout<<"Edge between the vertices "<<a<<" and"<< b<<" inserted\n";
}

void Graph::deleteEdge(int a,int b){
    if(a>numvertices || b>numvertices || a<0 || b<0){
        cout<<"Invalid vertices\n";
        return;
    }
    AdjMatrix[a][b]=0;
    cout<<"Edge between the vertices "<<a<<" and"<< b<<" inserted\n";
}

void Graph::searchEdge(int a,int b){
    if(a>numvertices || b>numvertices || a<0 || b<0){
        cout<<"Invalid vertices\n";
        return;
    }
    if(AdjMatrix[a][b]==1){
        cout<<"Edge exists between "<<a<<" and "<<b<<".\n";
    }
    else{
        cout<<"No Edge exists between "<<a<<" and "<<b<<".\n";
    }


}

void Graph::display(){
    cout<<"Adjacency Matrix\n";
    for(int i=0;i<numvertices;i++){
        for(int j=0;j<numvertices;j++){
            cout<<AdjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    int vertices;
    cout<<"Enter the number of vertices:";
    cin>>vertices;
    Graph g(vertices);
    int choice,a,b;

    while(true){
        cout<<"Enter 1 to insert\n";
        cout<<"Enter 2 to delete\n";
        cout<<"Enter 3 to search\n";
        cout<<"Enter 4 to display\n";
        cout<<"Enter 5 to exit";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter the vertices to insert a edge:";
            cin>>a>>b;
            g.insertEdge(a,b);
            break;

            case 2:
            cout<<"Enter the vertices to delete the edge:";
            cin>>a>>b;
            g.deleteEdge(a,b);
            break;

            case 3:
            cout<<"Enter the vertices to search the edge:";
            cin>>a>>b;
            g.searchEdge(a,b);
            break;

            case 4:
            g.display();
            break;

            case 5:
            cout<<"Exiting the menu";
            return 0;
            break;

            default:
            cout<<"Invalid choice entered";
            break;


        }

    }
}