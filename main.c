#include <stdio.h>
#include "graph.h"

int main(void)
{
  int option;
  int N, x, y, w;
  int res;
  int print_status = 1;

  Graph *G;

  scanf("%d", &option);

  while (option != -1)
  {
    switch (option)
    {

    /* --- case 0: criar grafo com N vértices --- */
    case 0:
      scanf("%d", &N);
      G = MyGraph(N);
      break;

    /* --- case 1: adicionar aresta --- */
    case 1: /* adicionamos */
      scanf("%d %d %d", &x, &y, &w);
      add_edge(G, x, y, w);
      break;

    /* --- case 2: verificar se aresta existe --- */
    case 2: /* exist_edge */
      scanf("%d %d", &x, &y);
      res = exist_edge(G, x, y);
      print_status = 0;
      break;

    /* --- case 3: vizinhos de um vértice --- */
    case 3:
      scanf("%d", &x);
      neighbors(G, x);
      break;

    /* --- case 4: remover aresta --- */
    case 4:
      scanf("%d %d", &x, &y);
      remove_edge(G, x, y);
      break;

    /* --- case 5: print_info --- */
    case 5:
      print_info(G);
      break;

    /* --- case 6: delete_graph --- */
    case 6:
      delete_graph(&G);
      printf("Grafo removido da memória.\n");
      break;

    /* --- case 7: max_neighbors --- */
    case 7:
      res = max_neighbors(G);
      print_status = 0;
      break;

    /* --- case 8: adjacency_matrix --- */
    case 8:
      adjacency_matrix(G);
      break;

    default:
      printf("unrecognized option %d!\n", option);
    }

    scanf("%d\n", &option);
  }

  /* Ao sair com -1: imprime info ou resultado da última query */
  if (option == -1)
  {
    if (print_status)
      print_info(G);
    else
      printf("%d\n", res);
  }

  delete_graph(&G);
  return 0;
}