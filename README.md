- Algoritmos y Estructura de Datos II -				7/6/22
 -- Segundo Parcial de Laboratorio --

Hemos definido correctamente las estructuras y funciones para una pila con prioridad, donde cada nodo contiene un elemento y una prioridad, y los elementos se ordenan según su prioridad.

Resumen de las funciones principales
Crear un nodo (create_node):

Recibe un elemento y su prioridad, y retorna un nodo inicializado con estos valores.
Destruir un nodo (destroy_node):

Libera la memoria del nodo.
Verificar invariante de representación (invrep):

Asegura que los nodos en la pila están ordenados correctamente según sus prioridades.
Crear una pila vacía (pstack_empty):

Inicializa una pila vacía con una prioridad máxima especificada.
Insertar un elemento (pstack_push):

Añade un nuevo nodo en la posición correcta según su prioridad.
Verificar si la pila está vacía (pstack_is_empty):

Retorna verdadero si la pila no contiene elementos.
Obtener el tamaño de la pila (pstack_size):

Retorna el número de elementos en la pila.
Obtener el elemento de mayor prioridad (pstack_top):

Retorna el elemento con la mayor prioridad.
Obtener la mayor prioridad (pstack_top_priority):

Retorna la prioridad más alta en la pila.
Eliminar el elemento de mayor prioridad (pstack_pop):

Elimina el nodo con la prioridad más alta de la pila.
Destruir la pila (pstack_destroy):
Libera toda la memoria asociada con la pila.


