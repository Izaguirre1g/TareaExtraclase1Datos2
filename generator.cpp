#include <iostream>
#include <fstream> // Creación, lectura y escritura de archivos
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

class Generator {
    // Atributos
private:
    string size;
    string outputFilePath;
public:
    // Constructor. Inicializa los miembros con sus respectivos parámetros
    Generator(string s, string path) : size(s), outputFilePath(path) {}

public:
    // Método de números random
    void writeRandomNumbers() {
        string numberSize = size;
        // Transformación del dato de entrada en mayúsculas
        transform(numberSize.begin(), numberSize.end(), numberSize.begin(), ::toupper);

        // Validación del tamaño de entrada para crear la cantidad de enteros
        if (numberSize == "SMALL") {
            generateRandomNumbers((512*1024*1024)/4); // Para 512MB
        } else if (numberSize == "MEDIUM") {
            generateRandomNumbers((1024*1024*1024)/4); // Para 1024MB (1GB)
        } else if (numberSize == "LARGE") {
            generateRandomNumbers((2048*1024*1024)/4); // Para 2048MB (2GB)
        } else {
            cout << "Tamaño ingresado desconocido. Debe usar small, medium o large" << endl;
        }
    }

        public:
    void generateRandomNumbers(int count) {

        ofstream file(outputFilePath, ios::binary | ios::out); // Abre el archivo en modo binario
        srand((time(0))); // Siempre generará valores aleatorios en cada vuelta
        if (file.is_open()) {
            for (int i = 0; i < count; i++) {
                int num = rand(); // Genera un número aleatorio
                if (num != 0){
                    file.write(reinterpret_cast<char*>(&num), sizeof(num)); // Escribe el número en formato binario
                }
            }
            file.close();
        } else {
            cout << "No se pudo abrir el archivo " << outputFilePath << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cout << "Uso: " << argv[0] << " -size <SIZE> -output <OUTPUT FILE PATH>" << endl;
        return 1;
    }

    string size, outputPath;

    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-size") {
            if (i + 1 < argc) {
                size = argv[++i];
            }
        } else if (string(argv[i]) == "-output") {
            if (i + 1 < argc) {
                outputPath = argv[++i];
            }
        }
    }

    Generator gen(size, outputPath);
    gen.writeRandomNumbers();

    return 0;
}






