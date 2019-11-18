#include<bits/stdc++.h>
using namespace std;


#define V 9 


int minDistance(int dist[], bool visited[]) 
{ 
	
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (visited[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 


void printSolution(int dist[]) 
{ 
	printf("Vertex \t\t Distance from Source\n"); 
	for (int i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i+1, dist[i]); 
} 


void dijkstra(int graph[V][V], int src) 
{ 
	int dist[V]; 

	bool visited[V]; 

	
	for (int i = 0; i < V; i++) 
	{	
	   dist[i] = INT_MAX;
	   visited[i] = false; 
	 
   }

	
	dist[src] = 0; 

	
	for (int count = 0; count < V - 1; count++) { 
		
		int u = minDistance(dist, visited); 
		visited[u] = true; 

		for (int v = 0; v < V; v++)  
			if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 

	printSolution(dist); 
} 
 
int main() 
{ 
	
	int graph[V][V];
	memset(graph, 0, sizeof(graph));
	
	cout << "Enter number of edges " << endl;
   int m ;
   cin >> m;
   
   cout << "Enter the vertices along with weight" << endl;
   for (int i = 0; i < m; i++){
      
      int v1,v2,w;
      cin >> v1 >> v2 >> w;
      graph[v1-1][v2-1] = w;
      graph[v2-1][v1-1] = w;
   }
   
	dijkstra(graph, 0); 
   
	return 0; 
} 

