#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <bits/stdc++.h>

#define INF 2147483647
#define INPUT_LIMIT 5000
using namespace std;

typedef struct sInput {
    int a, b;
    long long int c;
}Input;
vector<Input> input_arches(INPUT_LIMIT);

typedef struct sVertex {
    int u, v, ant;
    long long int c, f;

}Vertex;
vector<Vertex> graph(INPUT_LIMIT);

vector<int> ant;
int n, m, A;
long long int f, shortest_path, dd[INPUT_LIMIT], ant_p[INPUT_LIMIT];
bool visited[INPUT_LIMIT];

void compute_arch(int u, int v, long long int c, long long int f){
    Vertex vert;
    vert.u = u;
    vert.v = v;
    vert.c = c;
    vert.f = f;
    vert.ant = ant[u];
    graph[A] = vert;
    ant[u] = A++;
    vert.u = v;
    vert.v = u;
    vert.c = -c;
    vert.f = 0;
    vert.ant = ant[v];
    graph[A] = vert;
    ant[v] = A++;
}

void increment_path(int v, long long int minEdge){
    for (int i = ant_p[v]; i != -1; i = ant_p[graph[i].u])
        minEdge = min(minEdge, graph[i].f);

    for (int i = ant_p[v]; i != -1; i = ant_p[graph[i].u]) {
        graph[i].f -= minEdge;
        graph[i ^ 1].f += minEdge;
    }
    f = minEdge;
}
long long int minimum_path(int s, int t){
    for (int i = 0; i <= n + 1; ++i) {
        dd[i] = INF;
        ant_p[i] = -1;
        visited[i] = false;
    }
    queue<int> q;
    dd[s] = 0;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = ant[curr]; i != -1; i = graph[i].ant) {
            int v = graph[i].v;
            if (graph[i].f && dd[curr] + graph[i].c < dd[v]) {
                dd[v] = dd[curr] + graph[i].c;
                ant_p[v] = i;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        visited[curr] = false;
    }
    shortest_path = dd[t];
    return shortest_path;
}
int main(){
    int instancia = 0;
    long long int d, k;
    while (scanf("%d %d", &n, &m) != EOF) {
        long long int max_flow = 0, resp = 0;
        instancia++;
        A = 0;
        int fin = n+1;
        ant.assign(INPUT_LIMIT, -1);
        for (int i = 0; i < m; ++i){
            scanf("%d %d %lld", &input_arches[i].a, &input_arches[i].b, &input_arches[i].c);
        }
        scanf("%lld %lld", &d, &k);
        compute_arch(0, 1, 0, d); 
        compute_arch(fin-1, fin, 0, d); 
        for (int i = 0; i < m; ++i) {
            compute_arch(input_arches[i].a, input_arches[i].b, input_arches[i].c, k);
            compute_arch(input_arches[i].b, input_arches[i].a, input_arches[i].c, k);
        }

        do{
            shortest_path = minimum_path(0, fin);
            f = 0;
            increment_path(fin, INF);
            max_flow += f;
            resp += shortest_path * f;
            if (max_flow == d){
                break;
            }

        }while(shortest_path != INF);
        printf("Instancia %d\n", instancia);
        if (max_flow != d)
            printf("impossivel\n\n");
        else
            printf("%lld\n\n", resp);
    }
    return 0;
}
