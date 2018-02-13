#include "orgrash_search.cpp";

bool main()
{
  Graph graph;
  unsigned int vertex = 0, 
    path = 0;
  cin >> graph;
  cout << graph << "\n" << "Введите номер вершины, что вы желаете проверить: ";
  cin << vetrex;
  cout << "Введите расстояние, которое следует пройти к этой вершине: ";
  cin << path;
  CheckDistance(graph, path, vertex);
  system("pause");
  return false;
}
