#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

using namespace std;

// Clase principal
class Sorter {
protected:
    string inputFilePath;
    string outputFilePath;
    string code;

public:
    Sorter(string iFile, string oFile, string c) : inputFilePath(iFile), outputFilePath(oFile), code(c) {}

    void algorithm(string code) {
        // Recibe el algoritmo (parámetro) de ordenamiento a utilizar
        transform(code.begin(), code.end(), code.begin(), ::toupper);
        if (code == "QS") {
            Quick_Sort();
        } else if (code == "IS") {
            Insertion_Sort();
        } else if (code == "BS") {
            Bubble_Sort();
        } else {
            cerr << "Algoritmo no válido" << endl;
        }
    }

    void Quick_Sort(int arr[]) {
        
        int size = sizeof(arr) / sizeof(arr[0]);
        quickSort(arr, 0, size - 1);
        printArray(arr, size);
    }

    void Insertion_Sort() {
        int arr[] = {5, 2, 9, 1, 5, 6}; // Ejemplo de array a ordenar
        int size = sizeof(arr) / sizeof(arr[0]);
        insertionSort(arr, size);
        printArray(arr, size);
    }

    void Bubble_Sort(arr[]) {
        // Ejemplo de array a ordenar
        int size = sizeof(arr) / sizeof(arr[0]);
        bubbleSort(arr, size);
        printArray(arr, size);
    }

private:
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    void bubbleSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class PagedArray {
private:
    string inputFilePath;
    int pageHit, pageFault;
    static const int size_array = 128;  // `const` para permitir inicialización en la clase
    string *ptr;
    int p1[size_array];
    int p2[size_array];
    int p3[size_array];
    int p4[size_array];

public:
    // Constructor que lee un archivo binario y llena los arreglos
    PagedArray(string iFp): inputFilePath(iFp){}

    void readBinaryFile(string inputFilePath){
        ifstream inFile(inputFilePath, ios::in);

        string text;
        if (inFile.is_open()){
            while(!inFile.eof()){
                getline(inFile,text);
                cout<< text<< endl;
            }
        }
        inFile.close();
    }
    void get_PagedArray(){

    }
    void set_PagedArray(){

    }
};

// Se encarga de recibir los datos ingresados desde consola (archivos y algoritmos)
/*int main(int argc, char* argv[]) {
    if (argc != 7) {
        cout << "Uso: " << argv[0] << " -input <INPUT FILE PATH> -output <OUTPUT FILE PATH> -alg <ALGORITMO>" << endl;
        return 1;
    }

    string inputFilePath, outputFilePath, algorithm;

    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-input") {
            if (i + 1 < argc) {
                inputFilePath = argv[++i];
            }
        } else if (string(argv[i]) == "-output") {
            if (i + 1 < argc) {
                outputFilePath = argv[++i];
            }
        } else if (string(argv[i]) == "-alg") {
            if (i + 1 < argc) {
                algorithm = argv[++i];
            }
        }
    }

    try {
        PagedArray pagedArray(inputFilePath);  // Crear una instancia de PagedArray con el archivo de entrada
        Sorter sorter(inputFilePath, outputFilePath, algorithm);
        sorter.algorithm(algorithm);  // Ejecuta el algoritmo de ordenamiento
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}*/
int main (){
    PagedArray* arr = new PagedArray("C:/Users/Jose/OneDrive - Estudiantes ITCR/Escritorio/TEC/Algoritmos y Estructuras de Datos II/hhhh.txt");
    PagedArray page("C:/Users/Jose/OneDrive - Estudiantes ITCR/Escritorio/TEC/Algoritmos y Estructuras de Datos II/hhhh.txt");
    page.readBinaryFile("C:/Users/Jose/OneDrive - Estudiantes ITCR/Escritorio/TEC/Algoritmos y Estructuras de Datos II/hhhh.txt");

}
