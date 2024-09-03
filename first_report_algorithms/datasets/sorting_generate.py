import random
import csv

def generate_random_list(size, lrange):
    return [random.randint(0, lrange) for _ in range(size)]

def save_list(listaa, name):
    with open(name, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(listaa)

lista = generate_random_list(10000, 10000)
save_list(lista, 'sort.csv')
