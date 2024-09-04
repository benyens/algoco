import numpy as np


def generate_square_matrix(dimension, mrange):
    return np.random.randint(0, mrange, size=(dimension, dimension))

def generate_rectagular_matrix(row, column, mrange):
    return np.random.randint(0, mrange, size=(row, column))

def save_matrix(matrix, name):
    np.savetxt(name, matrix, delimiter=',')


square_matrix = generate_square_matrix(1000, 10000)
rectangular_matrix = generate_rectagular_matrix(1000, 2000, 10**4)

save_matrix(square_matrix, 'square_matrix.csv')
save_matrix(rectangular_matrix, 'rectangular_matrix.csv')