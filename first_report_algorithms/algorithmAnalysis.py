import pandas as pd
import matplotlib.pyplot as plt

carpeta = 'tiempos/'
archivo4 = carpeta +'10^4.csv'
archivo5 = carpeta +'10^5.csv'
archivoMatrix = carpeta +'MatrixMultiplication.csv'

df4 = pd.read_csv(archivo4)
df5 = pd.read_csv(archivo5)
dfMatrix = pd.read_csv(archivoMatrix)

def showplt(df, title, xlabel, ylabel, rotation):
    plt.figure(figsize=(12, 8))
    plt.bar(df['Nombre del Algoritmo'], df['Tiempo de Ejecución (segundos)'], color='green')
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.xticks(rotation=rotation)
    plt.tight_layout()
    plt.savefig('visuals/' + title)
    plt.show()

showplt(df4, 'Tiempos de Ejecución de Algoritmos con 10^4 Elementos', 'Algoritmos', 'Tiempo de Ejecución (segundos)', 80)
showplt(df5, 'Tiempos de Ejecución de Algoritmos con 10^5 Elementos', 'Algoritmos', 'Tiempo de Ejecución (segundos)', 80)
showplt(dfMatrix, 'Tiempos de Ejecución de Algoritmos con Matrices', 'Algoritmos', 'Tiempo de Ejecución (segundos)', 45)