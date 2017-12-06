#include "orgraph_search.h"
//В этом файле описан класс "граф"
istream& operator>>(istream& in, Graph& graph)
{//Перегрузка оператора ввода для графа.
    out << "Skolko v graphe budet vershin? VVOD: ";
    in >> graph.numberOfVertecies;
    SetMatrix(graph.adjacencyMatrix, graph.numberOfVertecies);
    for(unsigned i = 0; i < graph.numberOfVertecies; i++)
    {
        for(unsigned j = 0; j < graph.numberOfVertecies; j++)
        {
            out << "\nSMEZHNOST' VERSHIN " << i << " -> " << j << "\n0 - NET 1 - DA. VVOD: ";
            in >> graph.adjacencyMatrix[i][j];
        }
    }
    return in;
}
 
ostream& operator<<(ostream& out, Graph& graph)
{//Перегрузка оператора вывода для графа.
    if(graph.adjacencyMatrix != NULL)
    {//Если наш граф не пустой, то мы его отображаем с помощью матрицы инцидентности
        for(unsigned i = 0; i < graph.numberOfVertecies; i++)
        {
            for(unsigned j = 0; j < graph.numberOfVertecies; j++)
                out << graph.adjacencyMatrix[i][j] << " ";
            out << "\n";
        }
    }
    else
        out << "(0 VERSHIN)";
    return out;
}
 
unsigned Graph::GetNumberOfVerticies()
{
    return numberOfVertecies;
}
 
unsigned ** Graph::GetAdjacencyMatrix()
{//Гет-метод для матрицы смежности.
    return adjacencyMatrix;
}
 
Graph::~Graph()
{
    for(unsigned i = 0; i < numberOfVertecies; i++)
            delete [] adjacencyMatrix[i];
    delete [] adjacencyMatrix;
}
