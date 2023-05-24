// Step 1: Create a forest in such a way that each graph is a separate tree.
// Step 2: Create a priority queue Q that contains all the edges of the graph.
// Step 3: Repeat Steps 4 and 5 while Q is NOT EMPTY
// Step 4: Remove an edge from Q
// Step 5: IF the edge obtained in Step 4 connects two different trees, then Add it to the forest (for combining                two trees into one tree).
//               ELSE
//               Discard the edge
// Step 6: END
// CODE
#include<iostream>

#include <algorithm>

#include<vector>

using namespace std;


class edge{

    public:

    int s;

    int d;

    int w;

    edge(){


    }

    edge(int src,int des,int wei){

        s=src;

        d=des;

        w=wei;

    }

};


bool compare(edge e1,edge e2){

    return e1.w<e2.w;

}


int findparent(int i,int* parent ){

    if(parent[i]==i)

        return i;

    return findparent(parent[i],parent);

}


class graph{

    public:

    int e,n;

    edge* v;


    graph(int n,int e){

        this->n=n;

        this->e=e;

        v=new edge[e];

        for(int i=0;i<e;i++)

        {

            int x,y,w;

            cout<<"ENTER VERTICES AND WEIGHT OF EDGE "<<i+1<<" :	";

            cin>>x>>y>>w;

            edge e(x,y,w);

            v[i]=e;

        }

    }


    edge* unionfind(){

        int* parent=new int[n];

        for(int i=0;i<n;i++){

            parent[i]=i;

        }

        sort(v,v+e,compare);

        

        edge* output;

        output=new edge[n-1];

        int count=0,i=0;

        while(count!=n-1){

            edge c=v[i];

            int sourceparent=findparent(v[i].s,parent);

            int desparent=findparent(v[i].d,parent);

            if(sourceparent!=desparent){

                output[count]=c;

                parent[sourceparent]=desparent;

                count++;

            }

            i++;

        }

        int sum=0;

        cout<<endl<<"-------MST-------\n";

       for(int i=0;i<n-1;i++){

           cout<<output[i].s<<"	"<<output[i].d<<"	"<<output[i].w<<endl;

           sum+=output[i].w;

       }

       cout<<"\nWEIGHT OF MST IS "<<sum;

       return output;

    }

};


int main(){

    int n,e;

    cout<<"KRUSKAL'S ALGORITHM\nENTER NUMBER OF VERTICES :	";

    cin>>n;

    cout<<"ENTER NUMBER OF EDGEES :	";

    cin>>e;

    graph g(n,e);

    edge* mst=g.unionfind();

}

 