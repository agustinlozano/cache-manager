int myTest() {
    int cache_size = 3;

    CacheManager<Student> my_cache(cache_size);

    // Agrego dos estudiantes
    my_cache._insert("0", Student(0, 22, "Agustin L."));
    my_cache._insert("1", Student(1, 29, "Celeste T."));

    my_cache.listOftenUsedValues();

    cout << "Probando la funcion get de la clase CacheManager" << endl;
    auto objFromClass = my_cache.get("0");
    cout << "Nombre del estudiante: " << objFromClass.getData() << endl << endl;

    my_cache._insert("2", Student(2, 25, "Vicente L."));
    my_cache._insert("3", Student(3, 3, "Ninito L."));
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