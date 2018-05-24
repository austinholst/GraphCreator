#include <iostream>
#include <cstring>



//First step is being able to read in data. Maybe put the vertex's in a vector instead of array?

//when printing. Start with for loop that goes through and puts the top labels on
//Then another for loop going through the rows, and do [0][1],[0][2], etc. you can put the row label on that way also.

using namespace std;

//structs
struct vertex {
  char label[2]; 
};


//prototypes
void print(int matrix[20][20], vertex* vertexArray[20]);

//arrays
int matrix[20][20];    
vertex* vertexArray[20];  

//variables
bool running = true;
int vertexNum = 0;
int edgeNum = 0;
int height = 0;
int width = 0;

int main() {
  
  cout << "Welcome to graph creator" << endl;

  while(running) {
    cout << "You can 'add' 'delete' 'print' or 'quit'" << endl;
    char answer[10];
    cin.getline(answer, 10);
    
    //add
    if(strcmp(answer, "add") == 0) {
      cout << "Are you adding an edge or vertex?" << endl;
      char answer2[10];
      cin.getline(answer2, 10);
      cin.ignore(10, '\n');

      if(strcmp(answer2, "edge") == 0) {
	cout << "What is the first vertex?" << endl;
	char v1[2];
	cin >> v1;
	cout << v1 << endl;
	cout << "What is the second vertex?" << endl;
	char v2[2];
	cin >> v2;
	cout << v2 << endl;


	int vertex1 = -1;
	int vertex2 = -1;
	for(int i = 0; i <= 20; i++) {
	  cout << "What " << endl;
	  if(vertexArray[i] != NULL && (strcmp(v1, vertexArray[i]->label) == 0)) {
	    cout << "Here" << endl;
	    vertex1 = i;
	    cout << "Vertex1: " << vertex1 << endl;
	  }
	  cout << "Something" << endl;
	  cout << "asdf" << vertex1 << endl;
	}
	
	cout << "plas" << endl;
	cout << "asfasdffds" << vertex1 << endl;

	for(int i = 0; i <= 20; i++) {
	  if(vertexArray[i] != NULL && v2 == vertexArray[i]->label) {
	    vertex2 = i;
	  }
	}
	
	cout << "v1: " << vertex1 << endl;
	cout << "v2: " << vertex2 << endl;

	
	
      }
      else if(strcmp(answer2, "vertex") == 0){
	vertex* v = new vertex;
	cout << "What is the letter for the vertext label?" << endl;
	cin >> v->label;

	vertexArray[vertexNum] = v;
	vertexNum++;
      }
      else {
	cout << "That wasn't an option" << endl;
      }

    }
    //delete
    else if(strcmp(answer, "delete") == 0) {

    }
    //print
    else if(strcmp(answer, "print") == 0) {
      print(matrix, vertexArray);
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


void print(int matrix[20][20], vertex* vertexArray[20]) {
  //Print out the labels for the vertex's
  for(int i = 0; i <= 20; i++) {
    if(i == 20) {
      cout << "\n" << endl;
    }
    else if(vertexArray[i] == NULL) {
      cout << " "; 
    }
    else {
      cout << vertexArray[i]->label << " ";
    }
  }
}