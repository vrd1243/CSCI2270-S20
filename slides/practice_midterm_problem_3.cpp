#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct adjVertex {
    struct vertex * v;
};

struct vertex {
    int key;
    bool visited;
    int distance;
    vector <adjVertex> adj;
};

vector <vertex *> vertices;

// function to add edge between two vertices
void addEdge(int v1, int v2){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->key == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}


// function to add a vertex to the graph
void addVertex(int n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == n){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->key = n;
	v->visited = false;
	v->distance = -1;
        vertices.push_back(v);
    }
}

int countNodesWithDist(int id, int dist) {
    
    vertex * srcVertex = NULL;
    
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i]->key == id) { 
	    srcVertex = vertices[i];
	}
    }

    queue <vertex *> q;

    srcVertex->distance = 0;
    srcVertex->visited = true;
    q.push(srcVertex);
    
    int count = 0;
   
    while (!q.empty()) {
        vertex * v = q.front();
	q.pop();

	if (v->distance == dist) {
	    count++;
	}

        for (int i = 0; i < v->adj.size(); i++) {
	    if (v->adj[i].v->visited == false) {
	        v->adj[i].v->distance = v->distance + 1;
		v->adj[i].v->visited = true;
		q.push(v->adj[i].v);
	    }
	}
    } 
    return count;
}

int main(int argc, char * argv[]) {
    
    for (int i = 0; i < 5; i++)   	
        addVertex(i+1);	    

    addEdge(1, 4); 
    addEdge(2, 4); 
    addEdge(2, 5); 
    addEdge(3, 5); 
    addEdge(4, 1); 
    addEdge(4, 2); 
    addEdge(4, 5); 
    addEdge(5, 2); 
    addEdge(5, 3); 
    addEdge(5, 4); 

    int count = countNodesWithDist(3, 3);
    cout << "Count = " << count << endl;
    
}
