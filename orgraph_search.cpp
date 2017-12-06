#include "orgraph_search.h"
//В этом файле реализована функция, которая выполняет нашу задачу.
void CheckDistance(Graph graph, unsigned distance, unsigned vertex)
{//Функция, которая выводит все вершины, из которых существует путь в выбранную.
    unsigned ** pathCounts = SetMatrix(graph.GetNumberOfVerticies());
    for(unsigned k = 0; k < distance; k++)
    {
        for(unsigned i = 0; i < graph.GetNumberOfVerticies(); i++)
        {
            for(unsigned j = 0; j < graph.GetNumberOfVerticies(); j++)
                pathCounts[i][j] += graph.GetAdjacencyMatrix()[i][j] * graph.GetAdjacencyMatrix()[j][i];
        }
    }
    for(unsigned i = 0; i < graph.GetNumberOfVerticies(); i++)
    {
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
