# Proyecto de Algoritmos de Ordenamiento

Este proyecto implementa varios algoritmos de ordenamiento y técnicas de manejo de archivos CSV para la lectura y escritura de datos. El código está escrito en C++ y se utiliza un `makefile` para simplificar el proceso de compilación. Para la generación de Datasets se ocupa código escrito en Python que ese encuentra en `/datasets/`.

## Estructura del proyecto

- **`main.cpp`**: Contiene el punto de entrada principal del programa.
- **`algorithms.cpp`**: Implementaciones de los algoritmos de ordenamiento.
- **`algorithms.h`**: Contiene las definiciones y estrucuturas de los algoritmos implementados en `algorithms.cpp` .
- **`data_reader.cpp`**: Funciones para la lectura y escritura de archivos CSV.
-  **`data_reader.h`**: Contiene las definiciones de las funciones implementadas en `data_reader.cpp`
- **`algorithmAnalysis.py`**: Función para leer, analizar y graficar los datos.
- **`makefile`**: Archivo de construcción para compilar el proyecto.
- **`/bin/`**: Directorio donde se generan los ejecutables.
- **`/visuals/`**: Directorio donde se guardan los gráficos.
- **`/datasets/`**: Directorio que contiene el código generador de datasets y los datasets.
- **`/resultados/`**: Directorio que contiene los resultados entregados por los algoritmos al ser ejecutados.
- **`/tiempos/`**: Directorio que guarda los nombre y tiempos obtenidos por cada algoritmo.


## Requisitos

- Un compilador de C++ compatible con el estándar C++11 (por ejemplo, `g++`).
- Utilidades de línea de comandos estándar como `make`.
- Utilidades de análisis de tiempo, memoria, etc. como valgrind, gprof, ms_print. 


    
## Compilación

Para compilar el proyecto, sigue estos pasos:

1. **Asegúrate de tener las herramientas necesarias instaladas:**

   Para instalar las herramientas necesarias puedes utilizar el siguiente comando.

   ```bash
   sudo apt-get install g++ make
   ```

2. 
    - 2.1. **Para compilar y correr el código entero puedes utilizar los siguientes comandos:**

        ### Compilación
            ```
            make run_all
            ```
        
        #### Ejecutar
            ```
            make all
            ```

    - 2.2. **Para compilar y correr cada algoritmo por separado (No recomendado) puedes utilizar los siguientes comandos::**

        ### Compilación
            ```bash
            make <nombre_alg>_10_<4,5> # Para algoritmos de ordenamiento.
            make matrix_multiplication_<rectangular, square> # Para matrices (Si se quiere correr el optimizado se debe colocar `_optimized` al final)
            make matrix strassen # Para correr el Algoritmo de Strassen
            ```

        ### Ejecutar
            ```
            ./bin/<nombre_alg>_10_<4,5>
            ./bin/matrix_multiplication_<rectangular, square>
            ./bin/matrix strassen
            ```

3. **Si desea observar el uso de memoria y generar reportes (No es fundamental para este proyecto), puede utilizar los siguientes comandos:**
    
    - 3.1 **Uso del valgrind:** 
        ```
        valgrind --tool=massif .bin/run_all
        ```
    - 3.1.2 **Analizar el archivo creado:**
        ```bash
        ms_print massif.out.<número> # El número es el que tiene el archivo al ocupar massif en el valgrin
        ```


    - 3.2 **Generar reporte:**
        ```bash
        gprof .bin/run_all gmon.out > analysys.txt
        ```

## Muchas gracias por revisar el proyecto.