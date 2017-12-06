#include "orgraph_search.h"
//В этом файле реализована функция, которая выполняет нашу задачу.
void CheckDistance(Graph graph, unsigned distance, unsigned vertex)
{//Функция, которая выводит все вершины, из которых существует путь в выбранную.
    unsigned ** pathCounts = SetMatrix(graph.GetNumberOfVerticies()); //Матрица, в которой будет записанно из каких в какие вершины можно попасть за distance ребер.
    for(unsigned k = 0; k < distance; k++)
    {//Собственно, что-бы узнать какие вершины за путь k проходят к каким то вершинам. Нужно просто возвести матрицу смежности в степень k. Мы получим матрицу в которой будет видно в какие вершины из каких можно попасть пройдя k ребер.
        for(unsigned i = 0; i < graph.GetNumberOfVerticies(); i++)
        {
            for(unsigned j = 0; j < graph.GetNumberOfVerticies(); j++)
                pathCounts[i][j] += graph.GetAdjacencyMatrix()[i][j] * graph.GetAdjacencyMatrix()[j][i];
        }
    }
    for(unsigned i = 0; i < graph.GetNumberOfVerticies(); i++)
    {//Просто выводим те вершины, что ведут в выбранную. Просто нужно выписать в столбе все вершины, что дают true в столбе под номером выбранной вершины.
        if(pathCounts[i][--vertex])
            cout << i++ << " ";
    }
}
 
unsigned ** SetMatrix(unsigned number)
{
    unsigned ** pathCounts = new unsigned*[number];
    for(unsigned i = 0; i < number; i++)
        pathCounts[i] = new unsigned[number];
    for(unsigned i = 0; i < number; i++)
        for(unsigned j = 0; j < number; j++)
            pathCounts[i][j] = 0;
    return pathCounts;
}
