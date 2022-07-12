#ifndef CM
#define CM

#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>

using namespace std;

string RELATIVE_PATH = ".\\files\\data.txt";

template<class T>
class CacheManager {
    map <string, pair<T, int>> cache_data;
    int capacity;
    int MRU = 10;

    public:
        CacheManager(int);

        void _insert(string key, T obj);
        void show_cache();
        bool write_file();
        T get(string key);

        // Any other method...
        bool isFull(string, T);
        string getLru();
        void listOftenUsedValues();
};

/* Constructor de clase */
template <class T>
CacheManager <T> :: CacheManager(int size) {
    capacity = size;
}

/**
 * Checkear a partir de la key si en necesario
 * escribir la 'ram' ya sea para, actualizarla
 * y que sea consistente con la cache o porque
 * tengo que agregar un nuevo dato en ella.
 *
 * Esta funcionando!
 */
template <class T>
bool CacheManager <T> :: write_file() {
    ofstream myFile;

    myFile.open(RELATIVE_PATH, ios::out);

    if (myFile.fail()) {
        cout << "Error: no se pudo acceder el archivo.";
        exit(1);
    }

    for (auto x : cache_data) {
        myFile << x.first << " "
               << x.second.first.getId() << " "
               << x.second.first.getData() << " "
               << x.second.first.getValue() << endl;
    }

    myFile.close();

    return 0;
}

/**
 * A partir de la key inserto un objeto en la
 * cache y si es necesario escribir en la 'ram'
 *
 * Este metodo depende de write_file
 */
template <class T>
void CacheManager <T> :: _insert(string key, T obj) {
    // Si tengo la cache vacia
    if (cache_data.empty()) {
        // primero inserto en la cache
        cache_data.insert(make_pair(key, make_pair(obj, MRU)));

        // segundo inserto en el archivo 'ram'
        write_file();

    // Si no esta vacia
    } else {
        //checkeo si en necesario aplicar politica de reemplazo
        if (isFull(key, obj)) {
            // Primero tenemos que utilizar la politica de reemplazo
            string key = getLru();
            cache_data.at(key).first = obj;
            cache_data.at(key).second = ++MRU;

            // Luego, reescribimos el archivo para que la informacion
            // sea consistente. En esta implementacion volveriamos a
            // escribir todo el archivo ya que no se como podria ubicar
            // exactamente el dato que necesito actualizar.
            write_file();

        } else {
            //inserto el nuevo objeto en la cache y ram
            cache_data.insert(make_pair(key, make_pair(obj, ++MRU)));

            write_file();
        }
    }
}

/**
 * A partir de la key obtengo un objeto de la
 * cache o de la 'ram'.
 */
template <class T>
T CacheManager <T> :: get(string key) {
    cache_data.at(key).second = ++MRU;
    return cache_data.at(key).first;
}

template <class T>
void CacheManager <T> :: show_cache() {
    cout << "Capacidad actual: " << capacity
         << " MRU = " << MRU << endl;
}

/**
 * Devuelve la key del elemento almacenado en
 * la cache que tiene el valor de uso mas bajo.
 */
template <class T>
string CacheManager <T> :: getLru() {
    string lru_key = "";
    int LRU = MRU;

    for (auto x : cache_data) {
        auto pair_elm = x.second;

        if (LRU > pair_elm.second) {
            lru_key = x.first;
            LRU = pair_elm.second;
        }
    }

    return lru_key;
}

/**
 * Lista por pantalla los elementos de la cache
 * y sus respectivos valores de uso.
 */
template <class T>
void CacheManager <T> :: listOftenUsedValues() {
    for (auto x : cache_data) {
        int current_value = x.second.second;
        cout << "Elm " << x.first
             << " has a often-used value = " << current_value << endl;
    }

    cout << "\n" << endl;
}

/**
 * Checkea si la cache esta llena o no.
 */
template <class T>
bool CacheManager <T> :: isFull(string key, T obj) {
    return (int)cache_data.size() == capacity;
}

#endif
