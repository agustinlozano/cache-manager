#include "cm.h"

template <class T>
CacheManager <T> :: CacheManager(int) {}

template <class T>
CacheManager <T> :: ~CacheManager() {}

template <class T>
bool CacheManager<T> :: write_file(string key, T obj) {
    return true;
}

template <class T>
void CacheManager<T> :: _insert(string key, T obj) {}

template <class T>
T CacheManager<T> :: get(string key) {}
