#include <iostream>
#include <cstring>
#include <vector>


/* Author: Austin Holst
 * Date: 5 - 30 - 18
 * Code: Add and delete vertices and edges and creates and prints a adjacency matrix 
 */


using namespace std;

//structs
struct vertex {
  char label[2]; 
};


//prototypes
void print(int matrix[20][20], vertex* vertexArray[20], int counter);

//Adjacency Matrix
int matrix[20][20];
vertex* vertexArray[20];


//variables
bool running = true;
int vertexNum = 0;
int edgeNum = 0;
int height = 0;
int width = 0;
int counter = 0;

int main() {
  
  cout << "Welcome to graph creator" << endl;

  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < 20; j++) {
      matrix[i][j] = 0;
    }
  }

  while(running) {
    cout << "You can 'add' 'delete' 'print' or 'quit'" << endl;
    char answer[10];
    cin.getline(answer, 10);
    
    //add
    if(strcmp(answer, "add") == 0) {
     
      cout << "Are you adding an edge or vertex?" << endl;
      char answer2[10];
      cin.getline(answer2, 10);
      //cin.ignore(10, '\n');

      if(strcmp(answer2, "edge") == 0) {
	cout << "What is the first vertex?" << endl;
	char v1[2];
	cin >> v1;
	cin.ignore();
	cout << "What is the second vertex?" << endl;
	char v2[2];
	cin >> v2;
	cin.ignore();

	int vertex1 = -1;
	int vertex2 = -1;
	
	//Setting the first index
	for(int i = 0; i < 20; i++) {
	  if(vertexArray[i] != NULL && (strcmp(v1, vertexArray[i]->label) == 0)) {
	    vertex1 = i;
	  }
	}
	//Setting the second index
	for(int i = 0; i < 20; i++) {
	  if(vertexArray[i] != NULL && (strcmp(v2, vertexArray[i]->label) == 0)) {
	    vertex2 = i;
	  }
	}
	
	int weight;
	cout << "What is the weight of the edge?" << endl;
	cin >> weight;
	cin.ignore();

	matrix[vertex1][vertex2] = weight;
	
	
      }
      else if(strcmp(answer2, "vertex") == 0){
	vertex* v = new vertex;
	cout << "What is the letter for the vertext label?" << endl;
	cin >> v->label;
	cin.ignore();

	vertexArray[vertexNum] = v;
	vertexNum++;
	counter++;
      }
      else {
	cout << "That wasn't an option" << endl;
      }

    }
    //delete
    else if(strcmp(answer, "delete") == 0) {
      cout << "Do you want to delete an 'edge' or 'vertex'?" << endl;
      char answer3[10];
      cin.getline(answer3, 10);

      if(strcmp(answer3, "edge") == 0) {
	cout << "What is the first vertex?" << endl;
        char v1[2];
        cin >> v1;
        cin.ignore();
        cout << "What is the second vertex?" << endl;
        char v2[2];
        cin >> v2;
        cin.ignore();

        int vertex1 = -1;
        int vertex2 = -1;

        //Setting the first index
        for(int i = 0; i < 20; i++) {
          if(vertexArray[i] != NULL && (strcmp(v1, vertexArray[i]->label) == 0)) {
            vertex1 = i;
          }
        }
        //Setting the second index
        for(int i = 0; i < 20; i++) {
          if(vertexArray[i] != NULL && (strcmp(v2, vertexArray[i]->label) == 0)) {
            vertex2 = i;
          }
        }
	
	//set the edge back to no connection
        matrix[vertex1][vertex2] = 0;

      }
      else if(strcmp(answer3, "vertex") == 0) {
	char v[2];
	cout << "What is the vertex being deleted?" << endl;
	cin.getline(v, 2);
	int vertex1;
	
	//Finds the vertex in the array
	for(int i = 0; i < 20; i++) {
          if(vertexArray[i] != NULL && (strcmp(v, vertexArray[i]->label) == 0)) {
            vertex1 = i;
          }
        }
	
	//sets the matrix values equal to -1 so print function won't print them
	for(int i = 0; i < counter; i++) {
	  matrix[vertex1][i] = -1;
	  matrix[i][vertex1] = -1;
	}

	vertexArray[vertex1] = NULL;

      }
    }
    //print
    else if(strcmp(answer, "print") == 0) {
      print(matrix, vertexArray, counter);
    }
    //quit
    else if(strcmp(answer, "quit") == 0){
      running = false;
    }
    else {
      cout << "That wasn't an option" << endl;
    }
  }
  return 0;
} 


void print(int matrix[20][20], vertex* vertexArray[20], int counter) {
  
  cout << "Edges go from the rows to the columns" << endl; 
  cout << "  ";
  
  //Print out the labels for the vertex's
  for(int i = 0; i < counter; i++) {
    if(i == 20) {
      cout << "\n" << endl;
    }
    else if(vertexArray[i] == NULL) {
      cout << ""; 
    }
    else {
      cout << vertexArray[i]->label << " ";
    }
  }

  cout << " " << endl;
  
  //Print out the adjacency matrix
  for(int i = 0; i < counter; i++) {
    if(vertexArray[i] != NULL) {
      cout << vertexArray[i]->label << " ";
    }
    for(int j = 0; j < counter; j++) {
      if(matrix[i][j] != -1) {
	cout << matrix[i][j] << " ";
      }
    }
    if(vertexArray[i] != NULL) {
      cout << " " << endl;
    }
  }
}
