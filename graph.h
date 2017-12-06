class Graph{//Класс "Граф".
    unsigned numberOfVertecies; //Количество вершин в графе.
    unsigned ** adjacencyMatrix; //Двумерный массив, который является матрицой смежности.
public:
    Graph(): numberOfVertecies(0){};
    friend istream& operator>>(istream&, Graph&); //Перегрузка оператора ввода для графа.
    friend ostream& operator<<(ostream&, Graph&); //Перегрузка оператора вывода для графа.
    unsigned ** GetAdjacencyMatrix(); //ГетМетод для матрицы смежности.
    unsigned GetNumberOfVerticies(); //ГетМетод для количеств вершин в графе.
    ~Graph();
};
