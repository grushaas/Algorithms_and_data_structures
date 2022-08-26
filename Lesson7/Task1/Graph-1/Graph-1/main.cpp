#include <iostream>
#include <fstream>

class Graph
{
private:
	int vertexes;
	int** adjacency_matrix;
	bool* visited;
	
private:
	void Filling_in_matrix(std::ifstream &in, int** adjacency_matrix)
	{
		while (!in.eof())
		{
			for (int i = 0; i < vertexes; i++)
			{
				for (int j = 0; j < vertexes; j++)
				{
					int value;
					in >> value;
					adjacency_matrix[i][j] = value;
				}
			}
			in.close();
		}
	}

	void Print()
	{
		for (int i = 0; i < vertexes; i++)
		{
			for (int j = 0; j < vertexes; j++)
			{
				std::cout << "[" << i << "]" << "[" << j << "] = " << adjacency_matrix[i][j] << std::endl;
			}
		}
	}

public:
	Graph()
	{
		std::ifstream in("in.txt");
		in >> vertexes;

		visited = new bool[vertexes]();

		adjacency_matrix = new int* [vertexes];
		for (int i = 0; i < vertexes; i++)
		{
			adjacency_matrix[i] = new int[vertexes];
		}

		Filling_in_matrix(in, adjacency_matrix);
	}

	void dfs(int vertex)
	{
		visited[vertex] = true;
		std::cout << vertex << " ";
		for (int i = vertex; i < vertexes; i++)
		{
			for (int j = 0; j < vertexes; j++)
			{
				if (adjacency_matrix[i][j] == 1)
				{
					if (!visited[j])
					{
						dfs(j);
					}
				}
			}
		}
	}
};

int main()
{
	Graph* graph = new Graph();
	std::cout << "Vertex traversal order: ";
	graph->dfs(1);
}