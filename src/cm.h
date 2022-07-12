#ifndef CM
#define CM

#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>

using namespace std;

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
    // Si tengo la cache vacia
    if (cache_data.empty()) {
        cache_data.insert(make_pair(key, make_pair(obj, MRU)));

    // Si no esta vacia
    } else {
        //checkeo si en necesario escribir ram
        if (write_file(key, obj)) {
            //Investigar como escribir un archivo
            cout << "Cache llena necesitamos escribir ram" << endl;
        }

        //inserto el nuevo objeto en la ram
        MRU++;
        cache_data.insert(make_pair(key, make_pair(obj, MRU)));
    }

    // Si no esta vacia
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

}

#endif
