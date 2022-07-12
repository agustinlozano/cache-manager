#ifndef CM
#define CM

#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>

using namespace std;

string PATH = "\\files\\data.txt";

template<class T>
class CacheManager {
    map <string, pair<T, int>> cache_data;
    int capacity;
    int MRU = 1;

    public:
        CacheManager(int);
        //~CacheManager();

        void _insert(string key, T obj);
        void show_cache();
        bool write_file(string, T);
        T get(string key);

        // Any other method...
};

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
bool CacheManager <T> :: write_file(string key, T obj) {
    return (int)cache_data.size() == capacity;
}

/**
 * A partir de la key inserto un objeto en la
 * cache y si es necesario escribir en la 'ram'
 *
 * Este metodo depende de write_file
 */
template <class T>
void CacheManager <T> :: _insert(string key, T obj) {
    ofstream myFile;

    // Si tengo la cache vacia
    if (cache_data.empty()) {
        // primero inserto en la cache
        cache_data.insert(make_pair(key, make_pair(obj, MRU)));

        // segundo inserto en el archivo 'ram'
        myFile.open("data.txt", ios::out);

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

    // Si no esta vacia
    } else {
        //checkeo si en necesario escribir ram
        if (write_file(key, obj)) {
            cout << "Cache llena necesitamos escribir ram" << endl;

            // Primero tenemos que utilizar la politica de reemplazo
            // y conseguir tener la cache con la informacion apropiada
            // ...
            // ...

            // Luego, reescribimos el archivo para que la informacion
            // sea consistente. En esta implementacion volveriamos a
            // escribir todo el archivo ya que no se como podria ubicar
            // exactamente el dato que necesito actualizar.
            myFile.open("data.txt", ios::out);

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

        } else {
            //inserto solo el nuevo objeto en la cache
            MRU++;
            cache_data.insert(make_pair(key, make_pair(obj, MRU)));
        }


    }
}

/**
 * A partir de la key obtengo un objeto de la
 * cache o de la 'ram'.
 */
template <class T>
T CacheManager <T> :: get(string key) {
    return cache_data.at(key).first;
}

template <class T>
void CacheManager <T> :: show_cache() {
    cout << "Capacidad actual: " << capacity
         << " MRU = " << MRU << endl;
}

#endif
