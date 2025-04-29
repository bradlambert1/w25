#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string EQUATIONS_FILE = "equations.txt";

template <typename T>
class StackIt {
private:
    T table[512];
    static int index;

public:

    void push(T data) {
        if (index + 1 > 512) {
            cout << "STACK OVERFLOW!!!" << endl;
        }
        else {
            table[++index] = data;
        }
    }

    void pop() {
        if (index >= 0) {
            table[index--] = 0;
        }
        else {
            cout << "Erreur, pop non disponible" << endl;
        }
    }

    T top() {
        return table[index + 1];
    }

    int size() {
        return index;
    }

    bool isEmpty() {
        return (index == -1);
    }
};

template <typename T>
int StackIt<T>::index = -1;

void solve(string equation, string answer_string) {
  float answer = stoi(answer_string);
   #define DEF_eq equation;
   cout << DEF_eq;
  
}

void readFile() {
   fstream file;
   file.open(EQUATIONS_FILE);
   string line;
   string equation;
   string answer;
   while (!file.eof()) {
      getline(file, line, '=');
      equation = line;
      getline(file, line);
      answer = line;
      solve(equation, answer);
   }
}

int main() {

   cout << "t";
   return 0;
}