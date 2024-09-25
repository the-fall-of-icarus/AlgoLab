#include<stdio.h>
#include <stdbool.h>

#define MAX 100

int n;
int adj[MAX][MAX];
bool dominators[MAX][MAX];
bool visited[MAX];

void dfs(int start, int skip){
    if (start == skip) return; 
    visited[start] = true;
    for (int i = 0; i < n; i++) {
        if (adj[start][i] && !visited[i]) {
            dfs(i, skip);
        }
    }
}

void findDominators(){

    //finding nodes reachable from the start
    bool reachableFromStart[MAX] = {false};
    dfs(0, -1); 
    for (int i = 0; i < n; i++) {
        reachableFromStart[i] = visited[i];
    }

    //determining the denominators
    for(int i=0; i<n; i++){
        if(reachableFromStart[i]){
            //for each node j, check if j is a dominator of node i
            for (int j=0; j<n; j++){
                if(i==j){
                    dominators[i][j] = true; //each node is a dominator of itself
                }
                else {
                    //clearing the visited array before running each dfs traversal
                    for (int k=0; k<n; k++){
                        visited[k] = false; 
                    }

                    //run dfs from the source node, but skip node j
                    //if there exists a path without j, then j is not a dominator of i
                    dfs(0, j);

                    //if node i is unreachable for source when j is skipped, j is a dominator of i
                    dominators[i][j] !=visited[i];
                }
            }
        }
    }

}

int main() {
    int edges, u, v;

    // Input number of nodes and edges
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    printf("Enter the edges (u v) format:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    findDominators();

    return 0;
}
