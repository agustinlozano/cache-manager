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
    const char * getName() {
        return data;
    }

    int getValue() {
        return value;
    }

    ~Student() {}
};
const string Student :: class_name = "StudentClass";

// Any object can be stored in out CM
class Purchase {
    int ticketID;
    int price;
    string product_name;
    string note;

public:
    static const string class_name;

    Purchase(int _id, int _price, string _name, string _note):
        ticketID(_id),
        price(_price),
        product_name(_name),
        note(_note) {}

    void print() {
        cout << "Purchase data of " << product_name << endl;
        cout << "\tTicket ID: " << ticketID << endl;
        cout << "\t- Price " << price << endl;
        cout << "\t- Notes:" << endl;
        cout << note << endl;
    }
};
const string Purchase :: class_name = "PurchaseClass";

int main() {
    int cache_size = 15;

    CacheManager<Student> my_cache(cache_size);
    //CacheManager<Purchase> my_cache1(cache_size);


    my_cache._insert("0", Student(0, 22, "Student 1"));
    my_cache._insert("1", Student(1, 29, "Student 2"));

    cout << "Probando la funcion get de la clase CacheManager" << endl;
    auto objFromClass = my_cache.get("0");
    cout << "Nombre del estudiante: " << my_cache.get("0").getName() << endl;

    //my_cache._insert("2", Student(2, 25, "Student 3"));
    //my_cache._insert("3", Student(3, 30, "Student 4"));
    // ...
    // ...

    /*
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
