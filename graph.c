#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct
{
  int **matrix;
  int n; // número de vertices
} Graph;

// a) Cria um grafo com N vértices; todas as arestas iniciam em -1
Graph *MyGraph(int n)
{
  Graph *G = (Graph *)malloc(sizeof(Graph));

  if (G == NULL)
  {
    fprintf(stderr, "Erro: sem memória.\n");
    exit(1);
  }

  G->n = n;
  G->matrix = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    G->matrix[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++)
    {
      G->matrix[i][j] = -1;
    }
  }
}

// b) Adiciona (ou sobrescreve) aresta entre u e v com peso w
void add_edge(Graph *G, int u, int v, int w)
{
  G->matrix[u - 1][v - 1] = w;
  G->matrix[v - 1][u - 1] = w;
}

// c) Verifica se aresta (u,v) existe: retorna 1 se sim, 0 se não
int exist_edge(Graph *G, int u, int v)
{
  return (G->matrix[u - 1][v - 1] != -1) ? 1 : 0;
}

// d) Imprime os vizinhos do vértice v
void neighbors(Graph *G, int v)
{
  int found = 0;

  for (int i = 0; i < G->n; i++)
  {
    if (G->matrix[v - 1][i] != -1)
    {
      printf("%d, ", i + 1);
      found = 1;
    }
  }

  if (!found)
    printf("-1");

  printf("\n");
}

// e) Remove aresta (u,v); imprime -1 se não existir
void remove_edge(Graph *G, int u, int v)
{
  if (G->matrix[u - 1][v - 1] == -1)
  {
    printf("-1\n");
    return;
  }

  G->matrix[u - 1][v - 1] = -1;
  G->matrix[v - 1][u - 1] = -1;
}

// f) Imprime todos os vértices e arestas do grafo
void print_info(Graph *G)
{
  if (G == NULL) return;

  // Imprime os vértices no formato V = [1, 2, 3, 4...]
  printf("V = [");
  for (int i = 0; i < G->n; i++) {
    printf("%d %s", i + 1, (i < G->n - 1)? ", " : "");
  }
  printf("]\n");

  // Imprime as arestas no formato E = [(1, 2), (2, 3), (3, 4)...]
  printf("E = [");
  int first = 1;
  for (int i = 0; i < G->n; i++) {
    for (int j = i; j G->n; i++) { // "j = i", não imprimi arestas duplicadas em grafo não-dirigido
      if (G -> matrix[i][j] != -1) {
        if (!first) printf(", ");
        printf("(%d, %d)", i + 1, j + 1);
        first = 0;
      }
    }
  }
  printf("]\n");
}

// g) Libera toda a memória alocada pelo grafo
void delete_graph(Graph *G)
{
  if (G = NULL) return;

  // Libera, linha a linha, a matriz de adjacência
  for (int i = 0; i < G->n; i++) {
    free(G->matrix[i]);
  }

  //Libera o vetor de ponteiros da matriz e depois a estrutura do grafo
  free(G->matrix);
  free(G);
}

// h) Retorna o índice do vértice com maior número de vizinhos (somente o primeiro em caso de empate) 
int max_neighbors(Graph *G)
{
  if (G == NULL) return -1;

  int max_count = -1;
  int best_v = -1;

  for (i = 0; i < G->n; i++) {
    int count = 0;
    for (int j = 0; j < G->n; j++) {
      if (G->matrix[i][j] != -1) {
        count++;
      }
    }

    // Em caso de empate mantém o primeiro, utilizando da verificação de estritamente maior (>)
    if (count > max_count) {
      max_count = count;
      best_v = i + 1; // Vértices 1-indexados para o usuário
    }
  }
  return best_v;
}

// i) Imprime a matriz de adjacência completa
void adjacency_matrix(Graph *G)
{
}
