# Floyd-Warshall Algorithm 
Floyd-Warshall Algorithm is an algorithm for finding the shortest path between all the pairs of vertices in a weighted graph.

### CODE: 
```c++
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

const int INF = 1e7;

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];

void initialise(int V, vector<vector<int> >& graph)
{
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dis[i][j] = graph[i][j];

            // No edge between node i and j

            if (graph[i][j] == INF)
                Next[i][j] = -1;
            else
                Next[i][j] = j;
        }
    }
}


vector<int> constructPath(int u, int v)
{

    if (Next[u][v] == -1)
        return {};

    vector<int> path = { u };
    while (u != v) {
        u = Next[u][v];
        path.push_back(u);
    }
    return path;
}

void floydWarshall(int V)
{
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {

                if (dis[i][k] == INF || dis[k][j] == INF)
                    continue;

                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}


void printPath(vector<int>& path)
{
    int n = path.size();
    for (int i = 0; i < n - 1; i++)
        cout << path[i]+1 << " -> ";
    cout << path[n - 1]+1 << endl;
}

int main()
{

    int V = 4;
    vector<vector<int> > graph
        = { { 0, 3, INF, INF },
            { 2, 0, 2, INF },
            { INF, 5, 0, INF},
            { 20, INF, 8, 0 } };

    initialise(V, graph);

    floydWarshall(V);

    cout<<"  After :: "<<endl;

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;


    vector<int> path;

    cout << "Shortest path from 1 to 3: ";
    path = constructPath(0, 2);
    printPath(path);

    cout << "Shortest path from 4 to 1: ";
    path = constructPath(3, 0);
    printPath(path);

    cout << "Shortest path from 4 to 3: ";
    path = constructPath(3, 2);
    printPath(path);

    return 0;
}

```

### SOURCE:
[ShafaetPlanet](http://www.shafaetsplanet.com/?p=1927) 
[Programiz](https://www.programiz.com/dsa/floyd-warshall-algorithm)


# Bellman Ford's Algorithm
Bellman Ford algorithm helps us find the shortest path from a vertex to all other vertices of a weighted graph.  

It is similar to Dijkstra's algorithm but it can work with graphs in which edges can have negative weights.

### Why do we need to be careful with negative weights?
Negative weight edges can create negative weight cycles i.e. a cycle that will reduce the total path distance by coming back to the same point.  

Shortest path algorithms like Dijkstra's Algorithm that aren't able to detect such a cycle can give an incorrect result because they can go through a negative weight cycle and reduce the path length.  

### Bellman Ford vs Dijkstra
Bellman Ford's algorithm and Dijkstra's algorithm are very similar in structure. While Dijkstra looks only to the immediate neighbors of a vertex, Bellman goes through each edge in every iteration.  

### CODE: 
```c++

#include <bits/stdc++.h>
using namespace std;

#define M 100

const int INF = 1e7;
int cost[M][M];

void bell(vector<pair<int,int> > el, int V,int E,int src)
{
    int d[V];
    int i,j;

    for(i=0; i<V; i++)
    {
        d[i]=INF;
    }

    d[src] = 0;

    for(i=1; i<=V-1; i++)
    {
        for(j=0; j<E; j++)
        {
            int u = el[j].first;
            int v = el[j].second;

            if(d[u]+cost[u][v]<d[v]){
                d[v]=d[u]+cost[u][v];
            }
        }
    }

    for(j=0; j<E; j++)
    {
        int u = el[j].first;
        int v = el[j].second;

        if(d[u]+cost[u][v]<d[v]){
            cout<<"negative cycle"<<endl;
        }
    }


    for(i = 0; i<V; i++)
    {
        cout<<src+1<<"->"<<i+1<<"--------="<<d[i]<<endl;
    }
}


int main()
{
    int E, V;
    cin>>E>>V;

    vector<pair<int,int>> el;

    for(int i = 0; i<V; i++)
    {
        for(int j = 0; j<V; j++)
        {
            cost[i][j]=INF;
        }
    }

    for(int i = 0; i< E; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        cost[u-1][v-1] = w;
        el.push_back({u-1,v-1});

    }

    int src;
    cin>>src;
    bell(el,V,E,src-1);

    return 0;
}

/*
(1)
6 4
4 1 20
4 3 8
3 2 5
2 3 2
1 2 3
2 1 2
4

(2)
6 6
1 3 2
1 4 4
2 3 10
3 4 1
4 5 7
4 6 5
1

(3)
3 3
1 2 3
2 3 2
3 1 -10
1
*/
```

### SOURCE:
[ShafaetPlanet](http://www.shafaetsplanet.com/?p=2044)
[Programiz](https://www.programiz.com/dsa/bellman-ford-algorithm) 
