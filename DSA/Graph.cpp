#include <iostream>
#include <queue>  // For BFS
#include <stack>  // For DFS
using namespace std;

class Node {
public:
    int vertex;
    Node* next;
};

class AdjList {
public:
    Node* head;
};

class Graph {
public:
    int V;
    AdjList* array;

    Graph(int V) {
        this->V = V;
        array = new AdjList[V];
        for (int i = 0; i < V; i++) {
            array[i].head = nullptr;
        }
    }

    Node* createNode(int v) {
        Node* newNode = new Node;
        newNode->vertex = v;
        newNode->next = nullptr;
        return newNode;
    }

    void addEdge(int src, int dest) {
        Node* newNode = createNode(dest);
        newNode->next = array[src].head;
        array[src].head = newNode;

        newNode = createNode(src);
        newNode->next = array[dest].head;
        array[dest].head = newNode;
    }

    void displayGraph() {
        for (int i = 0; i < V; i++) {
            Node* temp = array[i].head;
            cout << "Vertex " << i << ":";
            while (temp) {
                cout << " -> " << temp->vertex;
                temp = temp->next;
            }
            cout << " -> NULL" << endl;
        }
    }

    // BFS Function
    void BFS(int startVertex) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS starting from vertex " << startVertex << ": ";

        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            Node* temp = array[currentVertex].head;
            while (temp) {
                int adjVertex = temp->vertex;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
                temp = temp->next;
            }
        }
        cout << endl;
        delete[] visited;
    }

    // DFS Helper (Recursive function)
    void DFSUtil(int vertex, bool visited[]) {
        visited[vertex] = true;
        cout << vertex << " ";

        Node* temp = array[vertex].head;
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                DFSUtil(adjVertex, visited);
            }
            temp = temp->next;
        }
    }

    // DFS Function (Recursive)
    void DFS(int startVertex) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        cout << "DFS starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
        cout << endl;

        delete[] visited;
    }

    ~Graph() {
        for (int i = 0; i < V; i++) {
            Node* current = array[i].head;
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] array;
    }
};

int main() {
    int V = 5;  // Number of vertices
    Graph g(V);

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Display the graph
    g.displayGraph();

    // Perform BFS
    g.BFS(0);

    // Perform DFS
    g.DFS(0);

    return 0;
}
