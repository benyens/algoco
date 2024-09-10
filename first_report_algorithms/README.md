**Para la compilación del programa es necesario lo siguiente:**

- Instalar g++ y añadirlo a PATH.


    
* _Compilación:_
    ```
    g++ -pg -o benchmark main.cpp data_reader.cpp algorithms.cpp -std=c++17 
    ```

* _Ejecutar:_
    ```
    ./benchmark
    ```

* _Profiling:_
    ```
    valgrind --tool=massif ./benchmark
    ```
    Luego para analizar el archivo creado: 
    ```
    ms_print massif.out.<número> # El número es el que tiene el archivo al ocupar massif en el valgrind 

* _Generar reporte:_
    ```
    gprof ./benchmark gmon.out > analysis.txt
    ```
