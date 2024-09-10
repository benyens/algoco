CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2
TARGET_DIR = bin
SRC = main.cpp algorithms.cpp data_reader.cpp 
DEPS = data_reader.h algorithms.h

# Crear el directorio de binarios
$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# Compilación de todo el código
run_all: $(TARGET_DIR)/run_all

$(TARGET_DIR)/run_all: $(SRC) $(DEPS) | $(TARGET_DIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET_DIR)/run_all -DRUN_ALL

# Ejecutar todo
all: run_all
	./$(TARGET_DIR)/run_all

# Limpiar archivos generados
clean:
	rm -f $(TARGET_DIR)/*

# Reglas de algoritmos por separado
define MAKE_ALGO_RULE
$1: $(TARGET_DIR)/$1

$(TARGET_DIR)/$1: $(SRC) $(DEPS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET_DIR)/$1 -D$2
endef

# Selection Sort
$(eval $(call MAKE_ALGO_RULE,selection_sort_10_4,ALG_SELECTION_10_4))
$(eval $(call MAKE_ALGO_RULE,selection_sort_10_4_med,ALG_SELECTION_MIDDLE_10_4))
$(eval $(call MAKE_ALGO_RULE,selection_sort_10_5,ALG_SELECTION_10_5))
$(eval $(call MAKE_ALGO_RULE,selection_sort_10_5_med,ALG_SELECTION_MIDDLE_10_5))

# Merge Sort
$(eval $(call MAKE_ALGO_RULE,merge_sort_10_4,ALG_MERGE_10_4))
$(eval $(call MAKE_ALGO_RULE,merge_sort_10_4_med,ALG_MERGE_MIDDLE_10_4))
$(eval $(call MAKE_ALGO_RULE,merge_sort_10_5,ALG_MERGE_10_5))
$(eval $(call MAKE_ALGO_RULE,merge_sort_10_5_med,ALG_MERGE_MIDDLE_10_5))

# Quick Sort
$(eval $(call MAKE_ALGO_RULE,quick_sort_10_4,ALG_QUICK_10_4))
$(eval $(call MAKE_ALGO_RULE,quick_sort_10_4_med,ALG_QUICK_MIDDLE_10_4))
$(eval $(call MAKE_ALGO_RULE,quick_sort_10_5,ALG_QUICK_10_5))
$(eval $(call MAKE_ALGO_RULE,quick_sort_10_5_med,ALG_QUICK_MIDDLE_10_5))

# C++ Sort
$(eval $(call MAKE_ALGO_RULE,cpp_sort_10_4,ALG_CPP_SORT_10_4))
$(eval $(call MAKE_ALGO_RULE,cpp_sort_10_4_med,ALG_CPP_SORT_MIDDLE_10_4))
$(eval $(call MAKE_ALGO_RULE,cpp_sort_10_5,ALG_CPP_SORT_10_5))
$(eval $(call MAKE_ALGO_RULE,cpp_sort_10_5_med,ALG_CPP_SORT_MIDDLE_10_5))

# Multiplicación de matrices
$(eval $(call MAKE_ALGO_RULE,matrix_multiplicaction_rectangular,ALG_MATRIX_MULTIPLICATION_RECTANGULAR))
$(eval $(call MAKE_ALGO_RULE,matrix_multiplicaction_square,ALG_MATRIX_MULTIPLICATION_SQUARE))
$(eval $(call MAKE_ALGO_RULE,matrix_multiplicaction_rectangular_optimized,ALG_OPTIMIZED_MULTIPLICATION_RECTANGULAR))
$(eval $(call MAKE_ALGO_RULE,matrix_multiplicaction_square_optimized,ALG_OPTIMIZED_MULTIPLICATION_SQUARE))
$(eval $(call MAKE_ALGO_RULE,strassen,ALG_STRASSEN))