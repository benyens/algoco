import random
import csv

def generate_random_list(size, lrange):
    return [random.randint(0, lrange) for _ in range(size)]

def generate_middle_sorted_list(size, sorted_percentage):
    n_sorted = int(size * sorted_percentage)
    lista = sorted([random.randint(0, 10**4) for _ in range(n_sorted)])
    lista.extend([random.randint(0, 10**4) for _ in range(size - n_sorted)])
    random.shuffle(lista)
    return lista

def save_list(listaa, name):
    with open(name, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(listaa)

lista = generate_random_list(10**4, 10**4)
save_list(lista, 'unsorted10^4.csv')

lista_middle = generate_middle_sorted_list(10**4, 0.4) # 40% sorted
save_list(lista_middle, 'sorted_middle10^4.csv')

lista = generate_random_list(10**5, 10**4)
save_list(lista, 'unsorted10^5.csv')

lista_middle = generate_middle_sorted_list(10**5, 0.6) # 60% sorted
save_list(lista_middle, 'sorted_middle10^5.csv')