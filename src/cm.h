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
    // <key, <Obj, index>>
    map <string, pair<T, int>> cache_data;
    int capacity;
    bool write_file(string, T);

    public:
        CacheManager(int) {};
        ~CacheManager() {};

        void show_cache();
        void _insert(string key, T obj);
        T get(string key);

        // Any other method...
};

#endif
