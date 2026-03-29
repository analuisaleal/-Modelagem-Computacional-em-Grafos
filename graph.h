
#ifndef GRAPH_H
#define GRAPH_H

typedef struct Graph Graph;

/* a) Cria um grafo com N vértices; todas as arestas iniciam em -1 */
Graph* MyGraph(int n);

/* b) Adiciona (ou sobrescreve) aresta entre u e v com peso w */
void add_edge(Graph *G, int u, int v, int w);

/* c) Verifica se aresta (u,v) existe: retorna 1 se sim, 0 se não */
int exist_edge(Graph *G, int u, int v);

/* d) Imprime os vizinhos do vértice v */
void neighbors(Graph *G, int v);

/* e) Remove aresta (u,v); imprime -1 se não existir */
void remove_edge(Graph *G, int u, int v);

/* f) Imprime todos os vértices e arestas do grafo */
void print_info(Graph *G);

/* g) Libera toda a memória alocada pelo grafo */
void delete_graph(Graph *G);

/* h) Retorna o índice do vértice com maior número de vizinhos */
int max_neighbors(Graph *G);

/* i) Imprime a matriz de adjacência completa */
void adjacency_matrix(Graph *G);

#endif 
