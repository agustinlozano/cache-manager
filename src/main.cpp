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

    const char * getData() {
        return data;
    }

    int getValue() {
        return value;
    }

    int getId () {
        return id;
    }

    ~Student() {}
};
const string Student :: class_name = "StudentClass";

int main() {
    int cache_size = 4;

    CacheManager<Student> my_cache(cache_size);

    // Agrego dos estudiantes
    cout << "---------------------- INCERT ---------------------" << endl;
    cout << "Se agregan los dos primeros elementos a la cache." << '\n' << endl;
    my_cache._insert("1", Student(0, 22, "Agustin L."));
    my_cache._insert("2", Student(1, 25, "Celeste T."));
    cout << endl;

    // Checkeo que los valores sean los esperados
    cout << "MOSTRAMOS CONTENIDO ACTUAL" << endl;
    my_cache.show_cache();

    // Accedo el elemento "0" por lo tanto queda con el MRU mas alto
    cout << "----------------------- GET -----------------------" << endl;
    cout << "Se accede a uno de los estudiantes en cache." << '\n' << endl;
    auto objFromClass = my_cache.get("1");
    cout << "Nombre del estudiante: " << objFromClass.getData() << '\n' << endl;

    // Checkeo nuevamente los valores y corroboro lo anterior
    cout << "MOSTRAMOS CONTENIDO ACTUAL" << endl;
    my_cache.show_cache();

    // Agrego dos estudiantes mas y colmo la cache

    cout << "---------------------- INCERT ---------------------" << endl;
    cout << "Se agregan otros dos elementos a la cache." << '\n' << endl;
    my_cache._insert("3", Student(2, 17, "Vicente L."));
    my_cache._insert("4", Student(3, 3, "Ninito L."));
    cout << endl;

    cout << "MOSTRAMOS CONTENIDO ACTUAL" << endl;
    my_cache.show_cache();

    // Este quinto elemento necesariamente debe eliminar uno
    // De los estudiantes aterires
    cout << "-------------------- UPDATE -----------------------" << endl;
    cout << "Un quinto elemento sera introducido a la cache de cap. 4" << '\n'
         << "por lo tanto el elemento menos usado fue reemplazado." << '\n' << endl;
    my_cache._insert("5", Student(4, 8, "Cato L."));
    cout << endl;

    // Vemos que alumno fue eliminado para poder almacenar a Cato L.
    cout << "MOSTRAMOS CONTENIDO ACTUAL" << endl;
    my_cache.show_cache();

    cout << "-------------------- UPDATE -----------------------" << endl;
    cout << "Ingresamos otro elemento con una key existente" << '\n'
         << "por lo tanto habra una actializacion." << '\n' << endl;
    my_cache._insert("4", Student(4, 8, "Bebe L."));
    cout << endl;

    // Vemos que el ultimo elemento ("3") fue actualizado
    cout << "MOSTRAMOS CONTENIDO ACTUAL" << endl;
    my_cache.show_cache();

    return 0;
}
