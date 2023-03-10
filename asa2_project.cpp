#include <vector>
#include <iostream>
#include <algorithm> 
#include <cstring> 

using namespace std;

int n_vertices = 0;
int n_bows = 0;
int n_max_trades = 0;

// Class edge refers to two vertices of the graph that are connected, and the
// weight of that connection. In this project, the weight is the cost of
// building the infrastructure between two regions, which are the vertices.
class Edge {

    // Atributes of the class edge
    private:
        int source;
        int destiny;
        int weight;

    public:
        Edge(int src, int des, int wght) {
            source = src;
            destiny = des;
            weight = wght;
        }

        // Getters for the class edge
        int getSource() { 
            return source; 
        }

        int getDestiny() { 
            return destiny; 
        }

        int getWeight() { 
            return weight; 
        }
};

// This function compares two edges' weight, making sure that when sorting
// the span tree, the edges are sorted by the highest weight to the smaller.
bool compare(Edge e1, Edge e2) {
    return (e1.getWeight() > e2.getWeight());
}

class Graph {

    // Atributes of the class graph
    private:
        int vertices; 
        vector<Edge> edges; 

    public:
        Graph(int v) {
            vertices = v;
        }

        void addEdge(int v1, int v2, int w) {
            Edge edge = Edge(v1, v2, w);
            edges.push_back(edge);
        }

        // From now on, there is an implementation of the Kruskal's algorithm,
        // which finds the minimum spanning tree of an undirected weighted
        // graph. Instead of searching for the lowest weight edges, which is
        // the most common application of this algorithm, we implemented it to 
        // get those who have the most weight, in order to get the shorter
        // path with the most trades possible between regions.

        int search(int subset[], int i) {
            if(subset[i] == -1)
                return i;
            return search(subset, subset[i]);
        }

        void join(int subset[], int v1, int v2) {
            int v1_set = search(subset,v1);
            int v2_set = search(subset,v2);
            subset[v1_set] = v2_set;
        }

        void getMaxSpannigTree() {
            int size_edges = edges.size();
            int number_of_important_edges = 0;

            sort(edges.begin(), edges.end(), compare);

            int *subset = new int[vertices];
            memset(subset, -1, sizeof(int) * (vertices + 1));

            for (int i = 0; i < size_edges; i++) {
                int v1 = search(subset, edges[i].getSource());
                int v2 = search(subset, edges[i].getDestiny());

                if(v1 != v2){
                    number_of_important_edges++;
                    n_max_trades += edges[i].getWeight();
                    join(subset,v1,v2);
                }
                if(number_of_important_edges == n_vertices - 1)
                    break;
            }
        }
};

// Function that reads the input and creates the graph
Graph readInput() {
    scanf("%d", &n_vertices);
    scanf("%d", &n_bows);
    Graph graph = Graph(n_vertices);
    for(int i = 0; i < n_bows; i++){
        int s, d, w;
        scanf("%d", &s);
        scanf("%d", &d);
        scanf("%d", &w);
        graph.addEdge(s, d, w);
    }

    return graph;
}

int main() {

    Graph graph = readInput();
    graph.getMaxSpannigTree(); 

    cout << n_max_trades << endl;

    return 0;
}
