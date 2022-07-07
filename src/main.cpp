#include "cm.h"

class Student {
    int id;
    int value;
    const char *data;

public:
    static const string class_name;

    Student(int _key, int _value, const char *_data):
        id(_key), value(_value), data(_data) {}

    void print() {
        cout << "Student Object: " <<
        id << ", " << value << ", " << data << endl;
    }

    ~Student() {}
};

// Any object can be stored in out CM

int main() {
    int cache_size = 15;
    CacheManager<Student> my_cache(cache_size);

    /*
    my_cache._insert("0", Student(0, 22, "Student 1"));
    my_cache._insert("1", Student(1, 29, "Student 2"));
    my_cache._insert("2", Student(2, 25, "Student 3"));
    my_cache._insert("3", Student(3, 30, "Student 4"));
    // ...
    // ...

    my_cache.show_cache();

    cout << " ---------------------- UPDATE -----------------------" << endl;
    my_cache.insert("2", Student(22, 3, "Ninito"));

    my_cache.show_cache();

    cout << "----------------------- GET -----------------------" << endl;
    Student return_obj = my_cache.get("0");

    cout << "-----------------------" << endl;
    my_cache.insert("2", Student(2, 4, "Ninito"));
    my_cache.show_cache();
    */

    // ...
    // ...

    return 0;
}
