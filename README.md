# Conversor de Números a Palabras

## Descripción

Este proyecto es un programa en C que convierte números enteros a su representación en palabras en inglés. Utiliza un archivo de diccionario (`numbers.dict`) que contiene las correspondencias entre números y sus nombres en inglés.

El programa lee un número desde la línea de comandos y lo convierte a palabras utilizando el diccionario proporcionado.

## Compilación

Para compilar el proyecto, utiliza el Makefile incluido:

```bash
make
```

Esto generará el ejecutable `rush-02`.

## Uso

El programa se ejecuta desde la línea de comandos con los siguientes argumentos:

- `./rush-02 <número>`: Utiliza el diccionario por defecto (`numbers.dict`) y convierte el número especificado.
- `./rush-02 <archivo_diccionario> <número>`: Utiliza un diccionario personalizado y convierte el número especificado.

### Ejemplos

```bash
# Usando el diccionario por defecto
./rush-02 42
# Salida: forty-two

# Usando un diccionario personalizado
./rush-02 mi_diccionario.dict 123
# Salida: one hundred twenty-three
```

## Archivos del Proyecto

- `main.c`: Punto de entrada del programa, maneja los argumentos y coordina la conversión.
- `converter.c/h`: Lógica principal de conversión de números a palabras.
- `file.c/h`: Funciones para leer y procesar el archivo de diccionario.
- `find_key.c/h`: Funciones para buscar claves en el diccionario.
- `memory.c/h`: Gestión de memoria para buffers.
- `utils.c/h`: Utilidades auxiliares, como validación de entrada.
- `error.c/h`: Manejo de errores.
- `numbers.dict`: Archivo de diccionario por defecto con números y sus nombres en inglés.
- `Makefile`: Script para compilar el proyecto.

## Requisitos

- Compilador C (como `cc` o `gcc`)
- Sistema operativo compatible con POSIX (para funciones como `write`)

## Limpieza

Para limpiar los archivos objeto y el ejecutable:

```bash
make clean    # Elimina archivos .o
make fclean   # Elimina archivos .o y el ejecutable
make re       # Recompila desde cero
```

## Autor

Colaborativo